# CodeQualityChecker
This is a small simulator which can be used to drive algorithms to measure their performance. You will get algorithm average run time in seconds within 85% confidence interval.

You can write any algorithm inside a function can be driven by the DriveFunc derivative. You can currently pass two arguments to your algorithms. There is a time vector as an argument which collects times spend for each run of the algorithm.

`samples` - How many times to run your algorithms since we measure average time this will be used as the minimum times the algorithm should run.  
`testSize` - This can be used to determine how much data you will use in your algorithm.  
`functionPtr` - This is the pointer to the algorithm you implemented

## How to build
Please use the make file. Tested with gcc 8.2.0
`make runOp` will make the program with -O3 level optimization and run  
`make runNoOp` will make the program without optimization and run

## What is faster ?
A simple C++ question. Try answering this question on your own. Then use the simulator. You may get surprised.
##### pattern 1
    result = ds.find(x)
    if (result) {
      other code 1
      ds.insert(x)
      other code 2
    }

##### pattern 2

    if (ds.insert(x).second) {
      other code 1
      other code 2
    }


## Task List
- [x] Change make file to run perf tool
- [ ] add a menu to choose each algorithm in run time
- [ ]  Improve template function driver
