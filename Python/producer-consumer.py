N = int(input("Enter the size of the buffer: "))
BUFFER  = []
k=0
l=0
MUTEX = 1
def wait(s):
	try:
		while(s<0):
			pass
		s-=1
		return(s)
	except:
		print("Argument must be an integer")
def signal(s):
	try:
		s+=1
		return(s)
	except:
		print("Argument must be an integer")

def producer(n):
	global BUFFER, MUTEX,k
	MUTEX = wait(MUTEX)
	k+=1
	BUFFER += [n]
	MUTEX = signal(MUTEX)
	print(f"Process{k} added to Buffer")
def consumer(n):
	global BUFFER,MUTEX,l
	MUTEX = wait(MUTEX)
	l+=1
	value = BUFFER.pop(BUFFER.index(n))
	MUTEX = signal(MUTEX)
	print(f"Process{l} removed from Buffer")
def main():
	command = int(input("\n1.Produce\n2.Consume\n3.Exit:\n=>"))
	if(command==1):
		if(MUTEX==1 and len(BUFFER)!=N):
			producer(1)
		else:
			print("Buffer is full\n")
	elif(command==2):
		if(MUTEX==1 and len(BUFFER)!=0):
			consumer(1)
		else:
			print("Buffer is empty\n")
	else:
		exit()
while(1):
	main()