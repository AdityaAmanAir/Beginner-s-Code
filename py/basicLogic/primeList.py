import numpy as np

primes = [1,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
X = primes * 26
Y=[]
for prime in primes:
    Y.extend([prime] * 26)

# List Z: Product of X[i] and Y[i]
Z = [X[i] * Y[i] for i in range(len(X))]

Z_train = np.array(Z)  # Your input values
X_train = np.array(X)  # Corresponding X outputs (X <= Y)
Y_train = np.array(Y) # Corresponding Y outputs

print(Z_train)
print(Y_train)
print(X_train)