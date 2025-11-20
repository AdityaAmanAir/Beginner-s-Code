import math as m
alist=[1,2,3,4,5,6]
alist.append(-1)
print(alist)
alist.sort()
print(alist)
a=alist.pop()
print(a)
print(alist)
print(alist.pop())
print(alist.remove(4))
print(alist)
blist=alist #alise and not a different copy
print(id(alist))
print(id(blist))
alist.append(77)
print(alist)
print(blist)
print(id(alist))
print(id(blist))
clist=alist.copy()
alist.append(69)
print(alist)
print(blist)
print(clist)
print(id(alist))
print(id(blist))
print(id(clist))
x=10
y=x
print(id(x), id(y))
x+=1
print(id(x), id(y))
z=-1.012 + 8
print(abs(z))
print(m.fabs(z))
# z=-1.012 + 8j
print(abs(z))
print(m.fabs(z))