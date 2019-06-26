#!/usr/bin/python3
import wobblepy
import unittest


class TestWobblepy(unittest.TestCase):
    def test_empty(self):
        self.assertIsNone(wobblepy.run_internal_tests())
        self.assertEqual(wobblepy.run_internal_tests.__name__, "run_internal_tests")
        self.assertEqual(wobblepy.run_internal_tests.__doc__, """run_internal_tests() -> None

run internal wobblepy tests""")


def main():
    return unittest.main()


if __name__ == "__main__":
    main()
