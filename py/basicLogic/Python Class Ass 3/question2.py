brics=["brazil","russia","india","china","south africa"]

country =input("Entet the name of the country : ")

country=country.lower()
if country in brics:
    print("Yes, it is a member of BRICS")
else:
     print("No, it is not a member of BRICS")    