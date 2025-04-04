# 4. A store manages its inventory using a dictionary. 
# Each product has a unique Product ID as the key, and its details like name, price, and stock are stored as a nested dictionary. 
# Implement the following operations using dictionary methods:
# 1. Add a New Product. 
# 2. Add the product - if already exists, use setdefault to ensure the price and stock have default values.
# 3. Check Product Availability using its Product ID.
# 4. List All Products with their details
# 5. Retrieve a Product’s Price
# 6. Update the stock by increasing and decreasing the stock of a specific product.
# 7. Remove a Product using its Product ID.
# 8. Clear Inventory


inventory = {
    "EAT001": {"NAME": "Biskit", "PRICE": "10", "STOCK": 49},
    "EAT002": {"NAME": "Role", "PRICE": "30", "STOCK": 30},
    "EAT003": {"NAME": "Ice Cream", "PRICE": "20", "STOCK": 13},
    "EAT004": {"NAME": "Cookies", "PRICE": "20", "STOCK": 19},
    "DDN001": {"NAME": "Oil", "PRICE": "85", "STOCK": 34},
    "DDN002": {"NAME": "Flour", "PRICE": "220", "STOCK": 9},
    "NES001": {"NAME": "Tooth Brush", "PRICE": "15", "STOCK": 22}
}

new_item = "EAT005"
if new_item not in inventory:
    inventory[new_item] = {"NAME": "Maggi", "PRICE": "15", "STOCK": 14}
    print(f"Product {new_item} added.")
else:
    print(f"Product {new_item} already exists.")

check=input("Enter Product ID: ")  
if check not in inventory:
    print("This Product is not listed ")
else:
        

