def infinite_sequence():
	count = 0
	while True:
		if count ==100000:
			break
		yield count
		count +=1



def is_palindrome(num):
    # Skip single-digit inputs
    if num // 10 == 0:
        return False
    temp = num
    reversed_num = 0

    while temp != 0:
        reversed_num = (reversed_num * 10) + (temp % 10)
        temp = temp // 10

    if num == reversed_num:
        return num
    else:
        return False
        
xx =0
for i in infinite_sequence():
    pal = is_palindrome(i)
    if pal:
    	print(pal)
    if xx==5:
    	break