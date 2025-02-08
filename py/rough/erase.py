planets = [
    "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"
]
a= input()
b= input()

c= planets.index(a)
d= planets.index(b)

if (c<d):
    print("CLOSER")
elif (d<c):
    print("FARTHER AWAY")    
else:
    print("THE SAME")    