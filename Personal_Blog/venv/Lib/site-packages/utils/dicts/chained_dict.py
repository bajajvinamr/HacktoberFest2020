try:
    from collections.abc import MutableMapping
except ImportError:
    from collections import MutableMapping
from itertools import chain


class ChainedDict(MutableMapping):

    def __init__(self, parent=None, **kwargs):
        self.__parent = parent
        self.__deleted_keys = set()
        self.__data = kwargs

    def __contains__(self, key):
        if self.__parent is not None:
            return (
                (key in self.__data or key in self.__parent)
                and key not in self.__deleted_keys
            )
        return key in self.__data

    def __getitem__(self, key):
        try:
            return self.__data[key]
        except KeyError:
            if self.__parent is not None and key not in self.__deleted_keys:
                return self.__parent[key]
            else:
                raise

    def __setitem__(self, key, val):
        self.__data[key] = val
        self.__deleted_keys.discard(key)

    def __delitem__(self, key):
        if key in self:
            self.__deleted_keys.add(key)
            try:
                del self.__data[key]
            except KeyError:
                pass
        else:
            raise KeyError(key)

    def __repr__(self):
        return "{}({})".format(self.__class__.__name__, dict(self.items()))

    def __iter__(self):
        return self.keys()

    def __len__(self):
        return len(list(self.keys()))

    def iterkeys(self):
        yielded = set(self.__deleted_keys)
        if self.__parent is None:
            iterable = self.__data.keys()
        else:
            iterable = chain(self.__parent.keys(), self.__data.keys())

        for key in iterable:
            if key in yielded:
                continue
            yield key
            yielded.add(key)

    keys = iterkeys

    def iteritems(self):
        for key in self.iterkeys():
            yield key, self[key]

    items = iteritems
