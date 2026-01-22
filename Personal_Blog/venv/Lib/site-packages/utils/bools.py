try:
    reduce
except NameError:
    from functools import reduce

def xor(*things):
    return reduce(lambda x, y: bool(x) ^ bool(y), things)
