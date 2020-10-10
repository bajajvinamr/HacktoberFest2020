def checkPalindrome(inputText):
    for i in range(int(len(inputText)/2)):
        if(inputText[i]!=inputText[-1-i]):
            return False
        
    return True
    
        
              
print(checkPalindrome('itopinonavevanonipoti'))
