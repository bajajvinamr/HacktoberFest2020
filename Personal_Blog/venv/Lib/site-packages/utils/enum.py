"""Who hasn't needed a good, old-fashioned enum now and then?"""


class _enum(object):

    def __call__(self, enum_name, *args, **kwargs):
        if args and kwargs:
            raise TypeError("enums can only be made from args XOR kwargs")

        enum_items = {}

        counter = 0
        for name, val in kwargs.items():
            if val is None:
                val = counter
                counter += 1
            elif isinstance(val, int):
                counter = val + 1

            enum_items[name] = val

        for val, name in enumerate(args, start=counter):
            enum_items[name] = val

        return type(enum_name, (Enum,), enum_items)

    def from_iterable(self, iterable):
        return self(*iterable)

    def from_dict(self, dct):
        return self(**dct)

    def __iter__(self):
        for k, v in self.__enum_items.items():
            yield k, v

    def __repr__(self):
        return "<{}: {}>".format(self.__class__.__name__, self.__enum_items.values())
enum = _enum()


class EnumItem(object):

    def __init__(self, parent, name, value):
        self.__parent = parent
        self.__name = name
        self.__value = value

    def __repr__(self):
        return "<{}: {} [{}]>".format(self.__class__.__name__, self.name, self.value)

    def __eq__(self, other):
        if isinstance(other, self.__class__):
            if self.parent.is_strict and self.parent != other.parent:
                raise ValueError("can't compare EnumItems from different enums")
            return self.value == other.value

        return self.value == other

    @property
    def value(self):
        return self.__value

    @property
    def name(self):
        return self.__name

    @property
    def parent(self):
        return self.__parent


class _EnumMeta(type):
    def __new__(cls, name, bases, attr_dict):

        options = attr_dict.pop('Options', object)

        attr_dict['__strict__'] = getattr(options, "strict_compare", True)

        new_enum = super(_EnumMeta, cls).__new__(cls, name, bases, {})

        enum_items = {}

        for attr_name, attr_value in attr_dict.items():
            if attr_name.startswith('__'):
                super(_EnumMeta, cls).__setattr__(new_enum, attr_name, attr_value)
                continue

            if getattr(options, 'force_uppercase', False):
                attr_dict.pop(attr_name)
                attr_name = attr_name.upper()

            enum_item = EnumItem(new_enum, attr_name, attr_value)

            enum_items[attr_name] = enum_item
            super(_EnumMeta, cls).__setattr__(new_enum, attr_name, enum_item)

        if getattr(options, "frozen", True):
            super(_EnumMeta, cls).__setattr__(new_enum, '__frozen__', True)
        else:
            super(_EnumMeta, cls).__setattr__(new_enum, '__frozen__', False)

        if getattr(options, "strict", False):
            super(_EnumMeta, cls).__setattr__(new_enum, '__strict__', True)
        else:
            super(_EnumMeta, cls).__setattr__(new_enum, '__strict__', False)

        super(_EnumMeta, cls).__setattr__(new_enum, '__enum_item_map__', enum_items)

        return new_enum

    def __setattr__(cls, name, val):
        if getattr(cls, "__frozen__", False):
            raise TypeError("can't set attributes on a frozen enum")

        if name in cls.__enum_item_map__:
            val =  EnumItem(cls, name, val)
            cls.__enum_item_map__[name] = val

        super(_EnumMeta, cls).__setattr__(name, val)

    @property
    def is_strict(cls):
        return getattr(cls, "__strict__", True)

    def get_name_value_map(cls):
        e = cls.__enum_item_map__
        return dict((e[i].name, e[i].value) for i in e)


class Enum(_EnumMeta("EnumBase", (object, ), {})):
    pass
