my_tuple = (1, 2, 3, 4, "Aman", 3.1415926, True, -100, False, -99)
print("Positive indices [3:8]:", my_tuple[3:8])


print("Negative index -7:", my_tuple[-7])
print("Slicing with step [::2]:", my_tuple[::2])

print("Reversed tuple:", my_tuple[::-1])


print("From start to index 5:", my_tuple[:5])


print("From index 5 to end:", my_tuple[5:])


print("Entire tuple:", my_tuple[:])

n = 3
print(f"Last {n} elements:", my_tuple[-n:])

print(f"First {n} elements:", my_tuple[:n])


a, b, *rest = my_tuple
print("Unpacked a, b:", a, b)
print("Rest:", rest)


print("Odd-index elements:", my_tuple[1::2])

print("Even-index elements:", my_tuple[0::2])
print("Subset of reversed tuple [1:5]:", my_tuple[::-1][1:5])



