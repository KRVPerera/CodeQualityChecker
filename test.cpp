#include <iostream>
#include <unordered_set>
#include <cassert>

#include "Utils.h"
#include "TestAlgorithms.h"
#include "Common.h"

using namespace std;
const int TEST_SIZE = 1000000;
const int INITIAL_SAMPLES = 10;

#define DriveFunc(x,y,z) functionDriver(x, y, &z, #z)

void functionDriver(int samples, int test_size, void (*drivenFunction)(int samples, int test_size, TimesVector& times), std::string functionName) {

    TimesVector times;
    cout << "\t running " << functionName.c_str() << " " << samples << " times\n";

    drivenFunction(samples, test_size, times);

    int prereq = samples;
    int req = RequiredSampleSize(times);
    while ( prereq < req ) {
        times.clear();
        prereq = req;
        cout << "\t not enough samples running " << functionName.c_str() << " " << req << " times\n";
        drivenFunction(req, test_size, times);
        req = RequiredSampleSize(times);
    }

    cout << "\t Average time after running " << prereq << " number of times\n";
    cout << "\t insert " << test_size << " number of ints " << functionName.c_str() << " time : " << Average(times) << " s\n";
}

void testSets(int samples, int test_size, int algo) {
    cout << "=== INTEGER SET TESTING ===" << std::endl;
    switch (algo) {
        case 1:
            DriveFunc(samples, test_size, insertToSetPattern1);
            break;
        case 2:
            DriveFunc(samples, test_size, insertToSetPattern2);
            break;
        case 3:
            DriveFunc(samples, test_size, insertToSetPattern1Random);
            break;
        case 4:
            DriveFunc(samples, test_size, insertToSetPattern2Random);
            break;
        default:
            break;
    }
}

void testMaps(int samples, int test_size) {
    cout << "=== INTEGER MAP TESTING ===" << std::endl;
    DriveFunc(samples, test_size, insertToMapPattern1);
    DriveFunc(samples, test_size, insertToMapPattern2);
    DriveFunc(samples, test_size, insertToMapPattern1Random);
    DriveFunc(samples, test_size, insertToMapPattern2Random);
}

void vclpPswAlgoTests(int samples, int test_size) {
    cout << "=== INTERSECTION algorithms ===" << std::endl;
    DriveFunc(samples, test_size, interSetNoSort);
    DriveFunc(samples, test_size, interSectVCLP);
    DriveFunc(samples, test_size, interSectAfterSort);
}

// TODO: add menu to choose which algo to run
// this helps running 'perf stat exe'
int main() {
    cout << "START" << endl;
    int algo, samples;
    cout << "choose algo : ";
    cin >> algo;
    cout << "choose samples : ";
    cin >> samples;
    testSets(samples, TEST_SIZE, algo);

    cout << endl;
    //testMaps(INITIAL_SAMPLES, TEST_SIZE);

    cout << endl;
    //vclpPswAlgoTests(INITIAL_SAMPLES, TEST_SIZE);

    return 0;
}
