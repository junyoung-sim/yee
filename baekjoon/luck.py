#!/usr/bin/env python3

import numpy as np
from os import listdir
from os.path import isfile, join

nums = []
for f in listdir("."):
    if isfile(join(".", f)) & (f.find("-") == -1):
        nums.append(f[:-4])
nums = np.array(nums)

print(np.random.choice(nums, size=1))
