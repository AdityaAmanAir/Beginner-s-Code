def elem(n,ind):
    if (ind==0):
        return print (n[ind])
    else:
        elem(n,ind-1)
        return  print(n[ind])


s=[1,2,3,4,5,6,7,8,9]
elem(s,5)