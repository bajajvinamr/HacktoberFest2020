_get_attr_raise_on_attribute_error = "RAISE ON EXCEPTION"

def get_attr(obj, string_rep, default=_get_attr_raise_on_attribute_error, separator="."):
    """ getattr via a chain of attributes like so:
    >>> import datetime
    >>> some_date = datetime.date.today()
    >>> get_attr(some_date, "month.numerator.__doc__")
    'int(x[, base]) -> integer\n\nConvert a string or number to an integer, ...
    """
    attribute_chain = string_rep.split(separator)

    current_obj = obj

    for attr in attribute_chain:
        try:
            current_obj = getattr(current_obj, attr)
        except AttributeError:
            if default is _get_attr_raise_on_attribute_error:
                raise AttributeError(
                    "Bad attribute \"{}\" in chain: \"{}\"".format(attr, string_rep)
                )
            return default

    return current_obj


class ImmutableWrapper(object):
    _obj = None
    _recursive = None

    def __init__(self, obj, recursive):
        self._obj = obj
        self._recursive = recursive

    def __setattr__(self, name, val):
        if name == "_obj" and self._obj is None:
            object.__setattr__(self, name, val)
            return
        elif name == "_recursive" and self._recursive is None:
            object.__setattr__(self, name, val)
            return

        raise AttributeError("This object has been marked as immutable; you cannot set its attributes.")

    def __getattr__(self, name):
        if self._recursive:
            return immutable(getattr(self._obj, name), recursive=self._recursive)

        return getattr(self._obj, name)

    def __repr__(self):
        return "<Immutable {}: {}>".format(self._obj.__class__.__name__, self._obj.__repr__())


def immutable(obj, recursive=True):
    """wraps the argument in a pass-through class that disallows all attribute
    setting. If the `recursive` flag is true, all attribute accesses will
    return an immutable-wrapped version of the "real" attribute."""
    return ImmutableWrapper(obj, recursive)
