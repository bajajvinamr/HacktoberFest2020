"""
This is the Karatsuba addition algoritm
"""


def karatsuba(num1, num2):
    """
    The Karatsuba algorithm to multiply 2 numbers.
    3 multiplications instead of 4.
    """
    if num1 < 10 or num2 < 10:
        return num1 * num2
    
    # Calculate the number size
    max_size = max(len(str(num1)), len(str(num2)))
    half_max = max_size // 2
    # Split the digit sequences at the middle
    high1, low1 = split_at(num1, half_max)
    high2, low2 = split_at(num2, half_max)
    # Recursively split the parts
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)
    # Calculate the number
    return (z2*10**(2*half_max)) + ((z1 - z2 - z0)*10**(half_max)) + z0


def split_at(num, splitter):
    """
    Split 2 number with the help of a splitter.
    """
    str_num = str(num)

    divided_num1, divided_num2 = str_num[:splitter], str_num[splitter:]

    return int(divided_num1), int(divided_num2)


if __name__ == '__main__':
    import time
    # Karatsuba
    start = time.time()
    kar_n = karatsuba(1234, 4321)
    fin_time1 = time.time() - start
    print("Karatsuba time:", fin_time1, "Result:", kar_n)
    # Regular
    start = time.time()
    mul_n = 1234*4321
    fin_time2 = time.time() - start
    print("Regular time:", fin_time2, "Result:", mul_n)
    # The time will still be bigger cuz of c++
    print(fin_time1 < fin_time2)
