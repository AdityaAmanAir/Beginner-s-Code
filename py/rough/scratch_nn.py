import numpy as np

# --- 1. Define the Neural Network Structure ---
class SimpleNeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size):
        """
        Initializes the weights for the neural network.
        
        Args:
            input_size (int): Number of input neurons (2 for XOR problem)
            hidden_size (int): Number of neurons in the hidden layer
            output_size (int): Number of output neurons (1 for XOR problem)
        """
        # Initialize weights with random values (mean 0)
        self.weights1 = np.random.rand(input_size, hidden_size)
        self.weights2 = np.random.rand(hidden_size, output_size)

    # --- 2. Define the Activation Function (Sigmoid) ---
    def sigmoid(self, s):
        """
        The sigmoid function squashes values to a range between 0 and 1.
        """
        return 1 / (1 + np.exp(-s))

    def sigmoid_derivative(self, s):
        """
        The derivative of the sigmoid function, used in backpropagation.
        """
        return s * (1 - s)

    # --- 3. Forward Propagation ---
    def forward(self, X):
        """
        Passes input data through the network to generate an output.
        """
        # Input layer to hidden layer
        self.z = np.dot(X, self.weights1)
        self.z2 = self.sigmoid(self.z) # Apply activation function
        
        # Hidden layer to output layer
        self.z3 = np.dot(self.z2, self.weights2)
        output = self.sigmoid(self.z3) # Final activation
        return output

    # --- 4. Backward Propagation ---
    def backward(self, X, y, output):
        """
        Calculates the error and adjusts the network's weights.
        This is where the "learning" happens.
        """
        # Calculate the error between the prediction and the actual answer
        self.output_error = y - output
        self.output_delta = self.output_error * self.sigmoid_derivative(output)

        # Calculate how much the hidden layer contributed to the output error
        self.z2_error = self.output_delta.dot(self.weights2.T)
        self.z2_delta = self.z2_error * self.sigmoid_derivative(self.z2)

        # Update the weights
        self.weights1 += X.T.dot(self.z2_delta)
        self.weights2 += self.z2.T.dot(self.output_delta)

    # --- 5. Training Function ---
    def train(self, X, y, epochs):
        """
        Repeatedly performs forward and backward propagation to train the model.
        """
        for i in range(epochs):
            output = self.forward(X)
            self.backward(X, y, output)
            if (i % 1000) == 0:
                loss = np.mean(np.square(y - output))
                print(f"Epoch: {i}, Loss: {loss:.4f}")

    def predict(self, X):
        """
        Makes a prediction on new data.
        """
        prediction = self.forward(X)
        # Round the output to 0 or 1
        return (prediction > 0.5).astype(int)

# --- Main Execution ---
if __name__ == "__main__":
    # Define the XOR problem dataset
    # Input data (X): pairs of binary values
    X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
    # Output data (y): the expected XOR result
    y = np.array([[0], [1], [1], [0]])

    # Create a neural network instance
    # Input layer has 2 neurons, hidden has 4, output has 1
    nn = SimpleNeuralNetwork(2, 4, 1)

    print("--- Starting Training ---")
    # Train the network for 10,000 epochs (iterations)
    nn.train(X, y, epochs=10000)
    print("--- Training Finished ---\n")

    # Make predictions on the input data
    predictions = nn.predict(X)

    print("--- Predictions vs Actual ---")
    for i in range(len(X)):
        print(f"Input: {X[i]} -> Predicted: {predictions[i][0]}, Actual: {y[i][0]}")