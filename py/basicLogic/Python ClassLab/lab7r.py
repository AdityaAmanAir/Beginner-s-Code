strings = []
n = int(input("How many strings? "))

for i in range(n):
    s = input(f"Enter string {i+1}: ")
    strings.append(s)

print("Your strings:")
for s in strings:
    print(s)