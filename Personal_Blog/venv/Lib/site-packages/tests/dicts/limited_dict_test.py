import pytest

from utils.dicts.limited_dict import LimitedDict


class LimitedDictTestCase(object):

    def test_init_with_args(self):
        with pytest.raises(KeyError):
            ld = LimitedDict([(1, 2)])

        ld = LimitedDict([(1, 2)], keys=[1])

        assert ld[1] == 2

    def test_init_with_kwargs(self):
        with pytest.raises(KeyError):
            ld = LimitedDict(the_key=True)

        ld = LimitedDict(the_key=True, keys=["the_key"])

        assert ld["the_key"] == True

    def test_defined_kes(self):
        keys = ["the_key", "another_key"]
        ld = LimitedDict(keys=keys)

        assert set(ld.defined_keys) == set(keys)

    def test_setitem_legal_key(self):
        ld = LimitedDict(keys=["the_key"])

        ld["the_key"] = True

        assert ld["the_key"] == True

    def test_setitem_illegal_key(self):
        ld = LimitedDict()

        with pytest.raises(KeyError):
            ld['any_old_key'] = None
