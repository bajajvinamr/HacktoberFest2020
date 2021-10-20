try:
    from collections.abc import Iterable
except ImportError:
    from collections import Iterable
import operator

# py3 doesn't include reduce as a builtin
try:
    reduce
except NameError:
    from functools import reduce


def product(sequence, initial=1):
    """like the built-in sum, but for multiplication."""
    if not isinstance(sequence, Iterable):
        raise TypeError("'{}' object is not iterable".format(type(sequence).__name__))

    return reduce(operator.mul, sequence, initial)
