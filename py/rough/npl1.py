# Import necessary libraries
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import layers 
import matplotlib.pyplot as plt

# -----------------
# 1. Load and Preprocess the Data
# -----------------
# The MNIST dataset is a classic for handwritten digit recognition.
# It consists of 60,000 training images and 10,000 testing images.
print("Loading and preprocessing the MNIST dataset...")
(x_train, y_train), (x_test, y_test) = keras.datasets.mnist.load_data()

# Normalize the pixel values to be between 0 and 1.
# This helps the neural network learn more effectively.
x_train = x_train.astype("float32") / 255.0
x_test = x_test.astype("float32") / 255.0

# Reshape the data to add a channel dimension (e.g., 28x28 -> 28x28x1).
# This is required for convolutional layers.
x_train = np.expand_dims(x_train, -1)
x_test = np.expand_dims(x_test, -1)

# One-hot encode the labels.
# For example, the digit '5' becomes a vector [0, 0, 0, 0, 0, 1, 0, 0, 0, 0].
num_classes = 10
y_train = keras.utils.to_categorical(y_train, num_classes)
y_test = keras.utils.to_categorical(y_test, num_classes)

print(f"Training data shape: {x_train.shape}")
print(f"Test data shape: {x_test.shape}")
print(f"Training labels shape: {y_train.shape}")
print(f"Test labels shape: {y_test.shape}")

# -----------------
# 2. Build the Neural Network Model (a simple CNN)
# -----------------
print("\nBuilding the Convolutional Neural Network (CNN) model...")
model = keras.Sequential(
    [
        # Input layer with the shape of our images.
        keras.Input(shape=(28, 28, 1)),
        # First convolutional layer.
        layers.Conv2D(32, kernel_size=(3, 3), activation="relu"),
        # Max pooling layer to downsample the feature maps.
        layers.MaxPooling2D(pool_size=(2, 2)),
        # Second convolutional layer.
        layers.Conv2D(64, kernel_size=(3, 3), activation="relu"),
        # Second max pooling layer.
        layers.MaxPooling2D(pool_size=(2, 2)),
        # Flatten the 3D output to a 1D vector.
        layers.Flatten(),
        # A dense hidden layer for learning complex patterns.
        layers.Dropout(0.5), # Dropout layer to prevent overfitting.
        layers.Dense(num_classes, activation="softmax"),
    ]
)

model.summary()

# -----------------
# 3. Train the Model
# -----------------
print("\nTraining the model...")
batch_size = 128
epochs = 5

# Compile the model with an optimizer, loss function, and metrics.
model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])

# Train the model on the training data.
model.fit(x_train, y_train, batch_size=batch_size, epochs=epochs, validation_split=0.1)

# -----------------
# 4. Evaluate the Model
# -----------------
print("\nEvaluating the model on the test data...")
score = model.evaluate(x_test, y_test, verbose=0)
print(f"Test loss: {score[0]:.4f}")
print(f"Test accuracy: {score[1]:.4f}")

# -----------------
# 5. Make Predictions
# -----------------
print("\nMaking predictions on a few test images...")
# Get the first 5 images from the test set.
predictions = model.predict(x_test[:5])

# Print the predicted and true labels for these images.
for i in range(5):
    predicted_label = np.argmax(predictions[i])
    true_label = np.argmax(y_test[i])

    # Plot the image.
    plt.imshow(x_test[i].reshape(28, 28), cmap='gray')
    plt.title(f"Predicted: {predicted_label}, Actual: {true_label}")
    plt.show()