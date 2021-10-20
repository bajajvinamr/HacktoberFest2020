from utils import lists

import pytest


class UnlistTestCase(object):

    def test_returns_single_element(self):
        assert lists.unlist(["thing"]) == "thing"

    def test_complains_if_multi_element(self):
        with pytest.raises(ValueError):
            lists.unlist([1, 2])

    def test_complains_if_empty(self):
        with pytest.raises(ValueError):
            lists.unlist([])

    def test_doesnt_complain_if_told_not_to(self):
        assert lists.unlist([1, 2], False) is None
        assert lists.unlist([], False) is None


class FlattenTestCase(object):
    def test_flattens_an_iterable(self):
        nested_iterable = [1, 2, 3, 4, [5, 6, [7, 8]]]
        assert lists.flatten(nested_iterable) == [1, 2, 3, 4, 5, 6, 7, 8]


class FlatmapTestCase(object):
    def test_maps_and_flattens(self):
        iterable = [1, 2, 3, 4, 5]
        expected = [1, 2, 2, 3, 4, 4, 5]

        def double_evens(e):
            if e % 2 == 0:
                return [e, e]
            else:
                return [e]

        assert lists.flat_map(iterable, double_evens) == expected
