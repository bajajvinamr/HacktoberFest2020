#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#
#Balanced brackets
# A bracket is considered to be any one of the following 
# characters: (, ), {, }, [, or ].

# Two brackets are considered to be a matched pair if the an opening 
# bracket (i.e., (, [, or {) occurs to the left of a closing bracket 
# (i.e., ), ], or }) of the exact same type. There are three types of 
# matched pairs of brackets: [], {}, and ().

# A matching pair of brackets is not balanced if the set of brackets 
# it encloses are not matched. For example, {[(])} is not balanced 
# because the contents in between { and } are not balanced. The pair 
# of square brackets encloses a single, unbalanced opening 
# bracket, (, and the pair of parentheses encloses a single, 
# unbalanced closing square bracket, ].
brackets = {"(":")","{":"}","[":"]"}


def isBalanced(arr):
    # Write your code here
    global brackets
    s = []
    for i in arr:
        if i in brackets.keys():
            s.append(i)
        else:
            #If brackets are present
            if s:
                top = s.pop()
                if brackets[top] != i:
                    return "NO"
            else:
                return "NO"
            
                    
    return "NO" if s else "YES"
                
                
            
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)
        

        fptr.write(result + '\n')

    fptr.close()
