"""List-related functions"""


def unlist(list_thing, complain=True):
    """transforms [Something] -> Something. By default, raises a ValueError for
    any other list values."""
    if complain and len(list_thing) > 1:
        raise ValueError("More than one element in {}".format(list_thing))
    elif len(list_thing) == 1:
        return list_thing[0]

    if complain:
        raise ValueError("Nothing in {}".format(list_thing))
    return None


def flatten(iterable):
    """Fully flattens an iterable:
    In: flatten([1,2,3,4,[5,6,[7,8]]])
    Out: [1,2,3,4,5,6,7,8]
    """
    container = iterable.__class__

    placeholder = []
    for item in iterable:
        try:
            placeholder.extend(flatten(item))
        except TypeError:
            placeholder.append(item)

    return container(placeholder)


def flat_map(iterable, func):
    """func must take an item and return an interable that contains that
    item. this is flatmap in the classic mode"""
    results = []
    for element in iterable:
        result = func(element)
        if len(result) > 0:
            results.extend(result)
    return results
