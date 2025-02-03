i=1
while i<=8:
    if i==3:
        print("lol")
        if i==3:
            print("continue")
            i+=1
            continue #loop starts again 
        print("not exe")  #9 to 13 did not exicuted and code continue the loop
        print(i)
        i+=1
        continue
        print("loool")
    print(i)
    if i==6:
            print("break")
            i+=1
            break
    i+=1