#Given a string write a function to check if it is a permutation of a pallindrome

# INPUT : Tact Coa

#Output : True (permutations: "taco cat", "atco cta", etc...)

def canPermutePallindrome(arr_str):
    hash = {}
    count = 0
    # No of times each character occured
    for i in arr_str:
        if i==" ":
            continue
        if i in hash:
            del hash[i]
        else:
            hash[i] = 1
        count += 1

    if count % 2==0:
        return len(hash)==0 #Expecting it to delete it fully
    else:
        return len(hash)==1 # #Expecting it to delete it having a single element

    #For matching use mod -> %
    #Any even no that is a match we can use in our pallindrome
     
s = ["taco cat","asma","chiprimermaid", "aabbc"]
for i in s:
    print(canPermutePallindrome(i.lower()))
