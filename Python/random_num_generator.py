import struct
import time

def lastbit(f):
    return struct.pack('!f', f)[-1] & 1

def getrandbits(k):
    "Return k random bits using a relative drift of two clocks."
    # assume time.sleep() and time.clock() use different clocks
    # though it might work even if they use the same clock
    #XXX it does not produce "good" random bits, see below for details
    result = 0
    for _ in range(k):
        time.sleep(0)
        result <<= 1
        result |= lastbit(time.clock())
    return result

def randint(a, b):
    "Return random integer in range [a, b], including both end points."
    return a + randbelow(b - a + 1)

def randbelow(n):
    "Return a random int in the range [0,n).  Raises ValueError if n<=0."
    # from Lib/random.py
    if n <= 0:
       raise ValueError
    k = n.bit_length()  # don't use (n-1) here because n can be 1
    r = getrandbits(k)          # 0 <= r < 2**k
    while r >= n: # avoid skew
        r = getrandbits(k)
    return r
print(*[randint(10, 110) for _ in range(20)])
