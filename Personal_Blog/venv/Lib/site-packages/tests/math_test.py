import pytest

from utils import math


class ProductTestCase(object):
    def test_empty_sequence(self):
        assert math.product([]) == 1

    def test_non_iterable(self):
        with pytest.raises(TypeError):
            math.product(None)
