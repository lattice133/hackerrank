#!/bin/python3


import math
import os
import random
import re
import sys


def solve(s):
    words = s.split(" ")
    indicator = 0
    for word in words:
        words[indicator] = word.capitalize()
        indicator = indicator + 1
    return " ".join(words)


if __name__ == "__main__":
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    s = input()
    result = solve(s)
    fptr.write(result + '\n')
    fptr.close()


