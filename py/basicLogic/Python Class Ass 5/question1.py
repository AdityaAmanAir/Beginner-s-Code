my_dict = {}
my_dict["name"] = "Aman"
my_dict["age"] = 19
my_dict["city"] = "Bhopal"
print("Initial Dictionary:", my_dict)
print("Keys:", list(my_dict.keys()))
print("Values:", list(my_dict.values()))
print("Items:", list(my_dict.items()))
print("Value for 'name':", my_dict.get("name"))
print("Value for 'country':", my_dict.get("country", "Not Found"))
my_dict["age"] = 20
print("After update:", my_dict)
my_dict.update({"city": "Khotri", "country": "India"})
print("After update with another dict:", my_dict)
removed_value = my_dict.pop("age")
print("Removed value:", removed_value)
print("After pop:", my_dict)
del my_dict["city"]
print("After del:", my_dict)
my_dict.clear()
print("After clear:", my_dict)
my_dict = {"a": 1, "b": 2, "c": 3}
print("New dictionary:", my_dict)
print("Keys iteration:")
for key in my_dict:
    print(key)
print("Values iteration:")
for value in my_dict.values():
    print(value)
print("Items iteration:")
for key, value in my_dict.items():
    print(f"{key}: {value}")
dict1 = {"x": 10, "y": 20}
dict2 = {"y": 25, "z": 30}
merged_dict = {**dict1, **dict2}
print("Merged dictionary:", merged_dict)
squared_dict = {k: v**2 for k, v in my_dict.items()}
print("Dictionary comprehension:", squared_dict)