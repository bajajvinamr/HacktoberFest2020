count = [0] * 256
word = "Legend" 
max = -1
repeated = '' 
for i in word: 
    count[ord(i)]+=1; 
  
for i in word: 
    if max < count[ord(i)]: 
        max = count[ord(i)] 
        repeated = i 
  
print("Repeated alphabet in the given string is {}".format(repeated))

