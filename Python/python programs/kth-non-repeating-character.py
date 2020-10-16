# Python 3 program to find kth  
# non-repeating character in a string 
MAX_CHAR = 256
 
def kthNonRepeating(str, k): 
  
    n = len(str) 
  
    count = [0] * MAX_CHAR 
  
    index = [0] * MAX_CHAR 
  
    for i in range( MAX_CHAR): 
        count[i] = 0
        index[i] = n 
  
    for i in range(n): 
       
        x = str[i] 
        count[ord(x)] += 1
  
        if (count[ord(x)] == 1): 
            index[ord(x)] = i 
  
        if (count[ord(x)] == 2): 
            index[ord(x)] = n 
  
    index.sort() 
  
    return index[k - 1] if (index[k - 1] != n) else -1

if __name__ == "__main__":
    
    my_string = input()
    k=int(input())
    res = kthNonRepeating(my_string, k) 
    if(res == -1): 
        print("There are less than k", 
              "non-repeating characters") 
    else: 
        print("kth non-repeating character is", my_string[res]) 
  