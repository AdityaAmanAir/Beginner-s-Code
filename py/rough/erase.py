# String Functions Examples
s = "Hello123"
print(s.isalpha())  # False (has numbers)
print(s.isdigit())  # False (has letters)
print(s.isalnum())  # True (letters and numbers)
print(s.lower())  # hello123
print(s.upper())  # HELLO123
print(s.find('lo'))  # 3 (position of 'lo')
print(s.count('l'))  # 2 (count of 'l')
print(s.replace('123', ' World'))  # Hello World
print(s.split('l'))  # ['He', '', 'o123']
print(' '.join(['Hello', 'World']))  # Hello World
print(s.strip('H3'))  # ello12
print(s.startswith('He'))  # True
print(s.endswith('123'))  # True

# Palindrome Generator
def generate_palindrome(text):
    return text + text[::-1]

word = "hello"
palindrome = generate_palindrome(word)
print(f"Palindrome of '{word}': {palindrome}")