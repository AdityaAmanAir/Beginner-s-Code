#Name : ADITYA AMAN
#REG. NO. : 24BAI10129

#Mask a Part of a String

email = "john.cse@example.com"
n=email.index("@")
print(email[:3]+ ('*'*8)+ email[n::])