import random
length = int(input("Enter the length of password:"))
lowcase = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
upcase = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
digits = ['0','1','2','3','4','5','6','7','8','9']
special = ['@','#','$','_','!','|','/','~']
all = lowcase + upcase + digits + special
p=" "
password = []
password = random.choice(lowcase) + random.choice(upcase) + random.choice(digits) + random.choice(special)
for i in range(length-4):
  password += random.choice(all)
pas=[]
pas[:0]=password
random.shuffle(pas)
for x in pas:
  p += x
print("password:",p)
