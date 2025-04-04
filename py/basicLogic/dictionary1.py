#LAB COMP. 1


# info={Name="Aditya Aman",
#       course="Problem Solving",
#       email="aditya.24bai10129@vitbhopal.ac.in",
#       reg="24BAI10129"}

info={1:"Aditya Aman",
      2:"Problem Solving",
      3:"aditya.24bai10129@vitbhopal.ac.in",
      4:"24BAI10129"}
print(info[1])
# print(info[0])  #key is not present

info[5]="VIT Bhopal University"
print(info[5])
info[3]="amanaditya1947@proton.me"
print(info[3])

print(1 in info)
print(100 in info)

copyinfo=info.copy()
print(copyinfo)

#print(info.items(1,"Aman"))

#(info.keys("24BAI10129"))

#print(info.values(1))

reg=info.pop(4)
print(reg)
print(info)


print("-------------------")
student = {"name": "Alice", "age": 21}
print(student.setdefault("grade", "A"))  # Output: A (inserts 'grade': 'A')
print(student)  # Output: {'name': 'Alice', 'age': 21, 'grade': 'A'}

print("-------------------")

#setdefault() to initilaize the list
scores = {}
scores.setdefault("math", []).append(90)
scores.setdefault("science", []).append(85)
print(scores)  # Output: {'math': [90], 'science': [85]}


#It will add the dictionary with the existing dictionary
a={1:"one",2:"two"} 
print(a)
b={4:"four"} 
a.update(b) 
print(a)

#It creates a dictionary from key and values
key={"apple","ball"} 
value="for kids" 
d=dict.fromkeys(key,value) 
print(d)

#length
print(a)
c=len(a)
print(c)


#clear()
print(a)
a.clear()
print(a)

# deleting the whole dictionary
a={1:"one",2:"two"} 
print(a)
del(a)
#print(a) #since the dictionar got deleted , so nameError has been thrown out


