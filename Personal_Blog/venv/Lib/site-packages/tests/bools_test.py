from utils import bools


class XORTestCase(object):
    def test_odd(self):
        things = [
            True,
            True,
            True,
            False,
            False,
            False,
            False,
        ]

        assert bools.xor(*things)

    def test_even(self):
        things = [
            True,
            True,
            False,
            False,
            False,
        ]

        assert not bools.xor(*things)
