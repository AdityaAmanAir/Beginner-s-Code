#Two body elastic collision

mass1=int(input("Mass 1 : "))
mass2=int(input("Mass 2 : "))
speed1=int(input("Speed of Mass 1 : "))
speed2=int(input("Speed of Mass 2 : "))

V1=(mass1-mass2)/(mass2+mass1)*speed1 + 2*mass2/(mass2+mass1)*speed2
V2=(mass1-mass2)/(mass2+mass1)*speed2 + 2*mass1/(mass2+mass1)*speed1

print(f"Speed of mass 1 after collision is {V1} \nSpeed of mass 2 after collision is {V2}")
