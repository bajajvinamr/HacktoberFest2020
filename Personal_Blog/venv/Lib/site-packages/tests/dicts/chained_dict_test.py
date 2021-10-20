import pytest

from utils.dicts.chained_dict import ChainedDict


class ChainedDictTestCase(object):

    def test_bare_initialization(self):
        ChainedDict()

    def test_contains_direct(self):
        cd = ChainedDict()
        cd["the_key"] = True

        assert "the_key" in cd
        assert "not_the_key" not in cd

    def test_contains_ancestral(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd, **{"the_other_key": True})

        assert "the_key" in  cd2
        assert "the_other_key" in cd2
        assert "the_other_key" not in cd

    def test_setitem_direct_not_affect_ancestral(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd)

        cd2["the_key"] = False

        assert cd2["the_key"] == False
        assert cd["the_key"] == True

    def test_ancestor_delitem(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd, **{"the_other_key": True})

        del cd["the_key"]

        assert "the_key" not in cd2

    def test_delitem(self):
        cd = ChainedDict({"the_key": True})
        del cd["the_key"]

        assert "the_key" not in cd

    def test_delitem_invalid_key(self):
        cd = ChainedDict()

        with pytest.raises(KeyError):
            del cd["anything"]

    def test_delitem_with_ancestor(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd)

        del cd2["the_key"]

        assert "the_key" not in cd2
        assert "the_key" in cd

    def test_len(self):
        cd = ChainedDict(**{"the_key": True})

        assert len(cd) == 1

    def test_len_with_ancestor(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd, **{"the_other_key": True})

        assert len(cd2) == 2

    def test_iter(self):
        cd = ChainedDict(**{"the_key": True})

        set(key for key in cd) == set(["the_key"])

    def test_iter_with_ancestor(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd, **{"the_other_key": True})

        assert set(key for key in cd2) == set(["the_key", "the_other_key"])
        assert set(key for key in cd) == set(["the_key"])

    def test_iter_with_ancestor_with_deletion(self):
        cd = ChainedDict(**{"the_key": True})
        cd2 = ChainedDict(parent=cd, **{"the_other_key": True})

        del cd2["the_key"]

        set(key for key in cd2) == set(["the_other_key"])
