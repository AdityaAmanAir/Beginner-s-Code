def mod(x, n, y):
    if n == 0:
        return 1
    half = mod(x, n // 2, y)
    result = (half * half) % y
    if n % 2 == 1:
        result = (result * (x % y)) % y
    return result

message = input("Enter your message: ")
A, B = 5, 221
encrypted = []

for ch in message:
    enc = mod(ord(ch), A, B)
    encrypted.append(chr(enc))  # Convert encrypted number to character

encrypted_message = ''.join(encrypted)  # Join characters into a string

print("Encrypted message:", encrypted_message)
