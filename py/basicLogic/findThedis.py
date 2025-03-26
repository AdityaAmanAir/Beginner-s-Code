import numpy as np
t=[0,2,4,6,8,10,12,14,16,18,20]
v=[0,10,18,25,29,32,20,11,5,2,0]

h=t[1]-t[0]
yO=v[0]
yn=v[-1]
ye=0
y_odd=0
for i in range(2,len(t)+1,2):
    ye+=t[i]
for i in range(1,len(t),2):
    y_odd+=t[i]    

result = h/3*(yO+yn+2*(ye)+4*(y_odd))  
print(result)  