try:
    from unittest import mock as mock
except ImportError:
    import mock as mock

import pytest

from utils import enum


class EnumItemTestCase(object):

    def test_equality(self):
        parent = mock.Mock()
        parent2 = mock.Mock()

        value1 = mock.Mock()
        value1.__eq__ = mock.Mock()
        value2 = mock.Mock()

        ei = enum.EnumItem(parent, "name", value1)
        ei2 = enum.EnumItem(parent2, "name", value2)
        parent.is_strict = False

        ei == ei2

        value1.__eq__.assert_called_once_with(value2)

    def test_equality_strict_enum(self):
        """Test that an EnumItem with a strict parent will not compared to
        an EnumItem from another parent."""
        parent = mock.Mock()
        parent2 = mock.Mock()
        parent.is_strict = True

        ei = enum.EnumItem(parent, "name", mock.ANY)
        ei2 = enum.EnumItem(parent2, "name", mock.ANY)

        with pytest.raises(ValueError):
            ei == ei2

    def test_equality_with_primitive(self):
        """Ensure that an enum's value is compared to a primitive"""
        value = mock.Mock()
        value.__eq__ = mock.Mock()
        ei = enum.EnumItem(mock.ANY, "name", value)

        ei == 1

        value.__eq__.assert_called_once_with(1)

class EnumClassTestCase(object):

    @pytest.fixture
    def enum_item_mock(self):
        return mock.create_autospec(enum.EnumItem)

    @pytest.fixture
    def enum(self, enum_item_mock):

        class TestEnum(enum.Enum):
            FLAG_ONE = 1
            FLAG_TWO = 2
            FLAG_THREE = 3
            FLAG_TRUE = True

        type.__setattr__(TestEnum, 'FLAG_MOCK', enum_item_mock)
        TestEnum.__enum_item_map__["FLAG_MOCK"] = enum_item_mock

        return TestEnum

    def test_attribute_acccess(self, enum, enum_item_mock):
        """Ensure that we're actually dealing with EnumItem instances"""
        assert enum.FLAG_MOCK is enum_item_mock

    def test_attribute_set_fails(self, enum):
        """Enums should default to frozen-type"""
        with pytest.raises(TypeError):
            enum.FLAG_THREE = 4

    def test_name_value_map(self, enum_item_mock, enum):
        expected_map = {
            "FLAG_ONE": 1,
            "FLAG_TWO": 2,
            "FLAG_THREE": 3,
            "FLAG_TRUE": True,
            enum_item_mock.name: enum_item_mock.value,
        }

        assert enum.get_name_value_map() == expected_map

    def test_is_strict(self, enum):
        """Enums should default to not-strict"""
        assert not enum.is_strict

class UnFrozenEnumClassTestCase(object):

    @pytest.fixture
    def enum(self):
        class TestEnum(enum.Enum):
            FLAG_ONE = 1
            FLAG_TWO = 2
            FLAG_THREE = 3
            FLAG_TRUE = True

            class Options:
                frozen = False

        return TestEnum

    def test_attribute_set(self, enum):
        assert enum.FLAG_THREE == 3
        enum.FLAG_THREE = 4
        assert enum.FLAG_THREE == 4


class StrictEnumClassTestCase(object):

    @pytest.fixture
    def enum(self):
        class TestEnum(enum.Enum):
            FLAG_ONE = 1
            FLAG_TWO = 2
            FLAG_THREE = 3
            FLAG_TRUE = True

            class Options:
                strict = True

        return TestEnum

    def test_is_strict(self, enum):
        """Strict enums should report as such"""
        assert enum.is_strict


class EnumFactoryTestCase(object):

    def test_creation(self):
        """Do we, in fact, create an Enum?"""
        new_enum = enum.enum("TestEnum")

        assert issubclass(new_enum, enum.Enum) == True
        assert new_enum.__name__ == "TestEnum"

    def test_creation_with_args(self):
        """Test that args are used to create sequential EnumItems"""
        new_enum = enum.enum("TestEnum", "ZERO", "ONE")

        assert isinstance(new_enum.ONE, enum.EnumItem) == True
        assert new_enum.ZERO == 0
        assert new_enum.ONE == 1

    def test_creation_with_kwargs(self):
        new_enum = enum.enum("TestEnum", TRUE=True, NONE=None, ONE=1)

        assert isinstance(new_enum.TRUE, enum.EnumItem)

        assert new_enum.TRUE == True
        assert new_enum.ONE == 1
        # kwargs non-deterministic ordering kinda makes this hard
        assert new_enum.NONE in [0, 2]

    def test_from_iterable(self):
        iterable = ["ONE", "TWO", "THREE"]
        with mock.patch("utils.enum._enum.__call__") as call_patch:
            enum.enum.from_iterable(iterable)

            call_patch.assert_has_calls([
                mock.call(*iterable),
            ])

    def test_from_dict(self):
        dct = {
            "ONE": 1,
            "TWO": 2,
            "THREE": 3,
        }

        with mock.patch("utils.enum._enum.__call__") as call_patch:
            enum.enum.from_dict(dct)

            call_patch.assert_has_calls([
                mock.call(**dct)
            ])
