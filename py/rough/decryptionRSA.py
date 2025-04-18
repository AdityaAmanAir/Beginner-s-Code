def mod(x, n, y):
    if n == 0:
        return 1
    half = mod(x, n // 2, y)
    result = (half * half) % y
    if n % 2 == 1:
        result = (result * (x % y)) % y
    return result

encrypted_message = input("Enter encrypted message: ")
C, B = 77, 221
decrypted = ""

for ch in encrypted_message:
    val = ord(ch)
    decrypted += chr(mod(val, C, B))

print("Decrypted message:", decrypted)
