a=0
b=0

def fun():
    global a
    a+=1
    c=10
    def nofun():
        nonlocal c #only the nested variable and not the global
