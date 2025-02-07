#Name : ADITYA AMAN
#REG. NO. : 24BAI10129

#Reverse Only a Part of a String

text = "abcdefg"
l= len(text)
n=l//2
print(text[:n-1:1] + text[n+1:n-2:-1] + text[n+2::1])