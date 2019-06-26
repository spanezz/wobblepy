#!/usr/bin/python3
import wobblepy
import unittest


class TestWobblepy(unittest.TestCase):
    def test_empty(self):
        self.assertIsNone(wobblepy.run_internal_tests())
        self.assertEqual(wobblepy.run_internal_tests.__name__, "run_internal_tests")
        self.assertEqual(wobblepy.run_internal_tests.__doc__, """run_internal_tests() -> None

run internal wobblepy tests""")

    def test_object(self):
        cls = wobblepy.TestObject
        self.assertEqual(cls.__doc__, "\nTest object for wobblepy python helpers\n")

        obj = cls()
        self.assertEqual(str(obj), "TestObject")
        self.assertEqual(repr(obj), "TestObject object")


def main():
    return unittest.main()


if __name__ == "__main__":
    main()
