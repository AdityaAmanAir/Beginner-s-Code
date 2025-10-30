def check_prime(n : int )-> bool:
    sq=int(n**(1/2))+1
    for i in range (2,sq +1):
        if(n%i==0):
            return True
    return False

num=int(input("Enter a number to check if it is prime or not : "))   
print("No! Not a prime" if check_prime(num) else "Yes, a prime" ) 
