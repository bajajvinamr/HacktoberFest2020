#Task
#The probability that a machine produces a defective product is 1/3. What is the probability that the 5th defect is found during the  inspection?
The first line contains the respective space-separated numerator and denominator for the probability of a defect, 
#and the second line contains the inspection we want the probability of being the first defect for:
#(1 3)
#(5)

n,d = list(map(int, input().split(" ")))
N = int(input())
p = float(n/d)
print(round(p*((1-p)**(N-1)),3))
