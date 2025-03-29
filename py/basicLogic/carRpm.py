import matplotlib.pyplot as mp

time=5
rpm =400
rpms=[0,50,100,200,400]
times=[]
for i in rpms:
    v=i/(rpm/time)
    times.append(v)
mp.plot(rpms,times)    
mp.show() 
