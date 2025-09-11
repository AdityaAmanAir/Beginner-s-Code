def find_primes(n):
    # Create a boolean array for prime numbers
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    # Return list of prime numbers
    return [i for i in range(n + 1) if is_prime[i]]

def to_binary(num):
    # Convert number to binary string, removing '0b' prefix
    return bin(num)[2:]

def main():
    try:
        n = int(input("Enter a positive integer n: "))
        if n < 1:
            print("Please enter a positive integer.")
            return
        
        primes = find_primes(n)
        if not primes:
            print(f"No prime numbers found between 1 and {n}.")
            return
        
        # Find the longest lengths for alignment
        max_prime_length = max(len(str(prime)) for prime in primes)
        max_binary_length = max(len(to_binary(prime)) for prime in primes)
        max_diff_length = max(len(str(primes[i+1] - primes[i])) for i in range(len(primes)-1)) if len(primes) > 1 else 3
        max_xor_length = max(len(to_binary(primes[i] ^ primes[i+1])) for i in range(len(primes)-1)) if len(primes) > 1 else 3
        
        # Adjust max lengths to account for "N/A"
        max_diff_length = max(max_diff_length, 3)
        max_xor_length = max(max_xor_length, 3)
        
        # Print header
        print("\nPrime Number | Binary Representation | Diff to Next | XOR with Next (Binary)")
        print("-" * (max_prime_length + max_binary_length + max_diff_length + max_xor_length + 14))
        
        # Print primes, their binary forms, differences, and XORs in columns
        for i, prime in enumerate(primes):
            binary = to_binary(prime)
            # Calculate difference to next prime (N/A for the last prime)
            diff = "N/A" if i == len(primes)-1 else str(primes[i+1] - primes[i])
            # Calculate XOR with next prime in binary (N/A for the last prime)
            xor = "N/A" if i == len(primes)-1 else to_binary(primes[i] ^ primes[i+1])
            # Align output
            print(f"{prime:<{max_prime_length}} | {binary:>{max_binary_length}} | {diff:>{max_diff_length}} | {xor:>{max_xor_length}}")
            
    except ValueError:
        print("Please enter a valid integer.")

if __name__ == "__main__":
    main()