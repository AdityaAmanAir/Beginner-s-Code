def is_prime(num): 
  i = 2 
  if num <= 1: 
    print("Number is not prime") 
  else:  
    for i in range(2, num): 
      if num % i == 0:
        print("Number is not prime")
      else:
        print("Number is prime")
  counter = 0
  while i <num: 
    if num%i ==0:
       counter += 1 
    i+=1
  if counter == 0: 
    print("Number is prime") 
  else: 
    print("Number is not prime")

num = int(input("Enter a number: "))
is_prime(num)