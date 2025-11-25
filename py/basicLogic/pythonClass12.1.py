import os
os.getcwd()

print(os.getcwd)

f = open("py/basicLogic/mywords.txt","r")
type(f)
print(f.readline()) # Reading one line of the file upto new line
print(f.readline())
print(f.readline(),end="")
print(f.readline())
print(f.readline(),end="")
print(f.readline())
f.close()