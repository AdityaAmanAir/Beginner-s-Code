d= {"Regd.No":10129,"Name":"Aditya","Branch":"CSE AIML" }
print ("d[“Regd.No‟]=",d["Regd.No"])
print ("d[“Name‟]=",d["Name"]) 
print ("d[“Branch‟]=",d["Branch"])
print("Number of key value pairs in dictionaryd=", len(d)) 
d["Gender"]="Male"
print ("dictionary d=",d)

del(d["Regd.No"])
print("dictionary d=",d)
print("\"Name\" in d=","Name"in d)
c=d.copy()
print("After copying dictionary d to c=",c)
print("value of key Name=",d.get("Name"))
print("Items of dictionary d=",d.items())
print("Keys of dictionary d=",d.keys( ))
print("Values of dictionary d=",d.values( ))
e={"Marks":94}
d.update(e)
print("After Updating dictionary d=",d)
print("sort :", sorted(d))
