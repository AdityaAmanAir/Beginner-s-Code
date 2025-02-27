a=["Aditya",'a',"man",69,-70,30+20j,"dog",70,54,70,"dog","lol"]
print(a)
b=a.copy()
print(b)
a.remove("man")
print(a)
a.remove(69)
print(a)
print(a.remove("dog"))
print(a)
a.remove(70)
print(a)
del a[6]
print(a)
a.pop()#defalt last element will be pop/removed/deleated
print(a)
print(b.count(69))
n=range(0,3)
print(n)
m=range(3)
print(m)
for i in m:
    print("my love")