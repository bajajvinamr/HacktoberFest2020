#According to Wikipedia :
#In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors,
#that is, the sum of its positive divisors excluding the number itself (also known as its aliquot sum).
#Equivalently, a perfect number is a number that is half the sum of all of its positive divisors (including itself).
# Problem Statement:
# Aliquot sum of a positive integer n is the sum of all proper divisors of n, that is, all divisors of n other than n itself.
# Let f(n) be the aliquot sum. Write a function which takes a positive integer as input and returns

# - "Alpha"  if f(n) < n
# "Gamma" if f(n) == n and
# "Beta" if f(n) > n
# Input: Positive Integer
# Output: String
# Sample Input: 6
#Sample Output: Gamma (Factor of 6 are 1, 2, 3 and sum of them is equals to 6)


# Here is the solution 
def aliquotSum(n):
    sm = 0
    if (n<0):
        return 0
    for i in range(1, n):
        if (n % i == 0):
            sm = sm + i
    return sm

def classify(n):
    sm = aliquotSum(n)
    if (sm == n):
        return "Gamma=
    elif (sm < n):
        return "Alpha"
    else:
        return "Beta"
