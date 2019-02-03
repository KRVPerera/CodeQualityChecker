runOp: runmeOpt
	./runmeOpt

runNoOp: runmeNoOpt
	./runmeNoOpt

runmeOpt: test.cpp Utils.h TestAlgorithms.h Common.h
	#gcc/8.2.0
	g++ -Wall test.cpp -std=c++0x -o runmeOpt -O3

runmeNoOpt: test.cpp Utils.h TestAlgorithms.h Common.h
	#gcc/8.2.0
	g++ -Wall test.cpp -std=c++0x -o runmeNoOpt

perfop: runmeOpt
	perf stat runmeOpt

perfNoOp: runmeNoOpt
	perf stat runmeNoOpt

clean:
	rm runmeNoOpt runmeOpt
