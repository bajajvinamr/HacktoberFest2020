#The series starts with 0 and 1 and the next number is the sum of previous two numbers 
def fibonacci(n):
	n1=0
	n2=1
	for i in range(n):
		print(n1)
		next = n1+n2 #the next number is sum of n1 and n2
		n1=n2 #n1 becomes n2
		n2=next #n2 gets value of next variable
		
n = int(input("Enter no of element in fibonacci series:"))

fibonacci(n)
