from sys import maxint 
def maxSubArraySum(a,size): 

    max_so_far = -maxint - 1
    max_ending_here = 0

    for i in range(0, size): 
        max_ending_here = max_ending_here + a[i] 
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 

        if max_ending_here < 0: 
            max_ending_here = 0   
    return max_so_far 


a = [1,2,3,-9,52,-12,-13,-15,19,15,100,-99] 
print "Maximum contiguous sum is", maxSubArraySum(a,len(a)) 
