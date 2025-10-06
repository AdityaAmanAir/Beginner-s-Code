import numpy as np
import pandas
import matplotlib.pyplot

input =np.array([1,2,3])
weight = np.array([[0.3,0.5, -0.33]])

weights1 = [0.2, 0.8, -0.5, 1]
weights2 = [0.5, -0.91, 0.26, -0.5]
weights3 = [-0.26, -0.27, 0.17, 0.87]

bias1 = 2
bias2 = 3
bias3 = 0.5 
output=[]
output[0] =(input[0]*weight[0] + input[1]*weight[1] +input[2]*weight[2])+bias1

inputs = [1, 2, 3, 2.5]

outputs = [
# Neuron 1:
inputs[0]*weights1[0] +
inputs[1]*weights1[1] +
inputs[2]*weights1[2] +
inputs[3]*weights1[3] + bias1,
# Neuron 2:
inputs[0]*weights2[0] +
inputs[1]*weights2[1] +
inputs[2]*weights2[2] +
inputs[3]*weights2[3] + bias2,
# Neuron 3:
inputs[0]*weights3[0] +
inputs[1]*weights3[1] +
inputs[2]*weights3[2] +
inputs[3]*weights3[3] + bias3]