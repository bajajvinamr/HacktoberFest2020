try:
    from collections.abc import MutableMapping
except ImportError:
    from collections import MutableMapping


class LimitedDict(MutableMapping):
    def __init__(self, args=None, **kwargs):
        keys = kwargs.pop('keys', [])
        self.__keys = keys

        self.__data = {}

        if args:
            kwargs.update((key, val) for key, val in args)

        for key, val in kwargs.items():
            self[key] = val

    def __setitem__(self, key, val):
        if key not in self.__keys:
            raise KeyError("Illegal key: {}".format(key))

        self.__data[key] = val

    def __getitem__(self, key):
        return self.__data[key]

    def __iter__(self):
        return self.__data.__iter__()

    def __delitem__(self, key):
        del self.__data[key]

    def __len__(self):
        return len(self.__data)

    def __repr__(self):
        return "{}({}, {})".format(self.__class__.__name__, self.defined_keys, self.__data)

    @property
    def defined_keys(self):
        return self.__keys
