#ifndef TEST_ALGORITHMS_H
#define TEST_ALGORITHMS_H
#include "Common.h"
#include <iostream>

#define preExit(x) if (x > 50) return

#define RANDOM_RANGE 100000

void insertToSetPattern1(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            if (intSetp1.find(i) == intSetp1.end()) {
                intSetp1.insert(i);
                intVec.push_back(i);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}


void insertToSetPattern1Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            int val = rand() % RANDOM_RANGE + 1;
            if (intSetp1.find(val) == intSetp1.end()) {
                intVec.push_back(val);
                intSetp1.insert(val);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern3Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp3;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {

            int val = rand() % RANDOM_RANGE + 1;
            IntSet::iterator lb = intSetp3.lower_bound(val);

            if ((lb != intSetp3.end()) && !intSetp3.key_comp()(val, *lb)) {
            } else {
                intSetp3.insert(lb, val);
                intVec.push_back(val);
            }     
        }
        
        auto finish = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
//std::cout << "IntVec : " << intVec.size() << " elapsed : " << elapsed_seconds << std::endl;

        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern4Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp3;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {

            int val = rand() % RANDOM_RANGE + 1;
            IntSet::iterator lb = intSetp3.upper_bound(val);

            if ((lb != intSetp3.end()) && !intSetp3.key_comp()(val, *lb)) {
            } else {
                intSetp3.insert(lb, val);
                intVec.push_back(val);
            }     
        }
        
        auto finish = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();

        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern2Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            int val = rand() % RANDOM_RANGE + 1;
            if (intSetp1.insert(val).second) {
                intVec.push_back(val);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern2(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            if ( intSetp1.insert(i).second) {
                intVec.push_back(i);
            }
        }

        auto finish = std::chrono::steady_clock::now();
        //std::cout << "IntVec : " << intVec.size() << std::endl;

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern3(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp3;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {

            IntSet::iterator lb = intSetp3.lower_bound(i);

            if ((lb != intSetp3.end()) && !intSetp3.key_comp()(i, *lb)) {
            } else {
                intSetp3.insert(lb, i);
                intVec.push_back(i);
            }     
        }
        
        auto finish = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        //std::cout << "IntVec : " << intVec.size() << " elapsed : " << elapsed_seconds << std::endl;

        times.push_back(elapsed_seconds);
    }
}

void insertToSetPattern4(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntSet intSetp3;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {

            IntSet::iterator lb = intSetp3.upper_bound(i);

            if ((lb != intSetp3.end()) && !intSetp3.key_comp()(i, *lb)) {
            } else {
                intSetp3.insert(lb, i);
                intVec.push_back(i);
            }     
        }
        
        auto finish = std::chrono::steady_clock::now();
        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        //std::cout << "IntVec : " << intVec.size() << " elapsed : " << elapsed_seconds << std::endl;

        times.push_back(elapsed_seconds);
    }
}

void insertToMapPattern1(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntBoolMap intMapP1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            if (intMapP1.find(i) == intMapP1.end()) {
                intMapP1.insert(IntBool(i, true));
                intVec.push_back(i);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToMapPattern2(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    for (int t = 0; t < samples ; ++t) {
        IntBoolMap intMapP2;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            if (intMapP2.insert(IntBool(i, true)).second) {
                intVec.push_back(i);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToMapPattern1Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntBoolMap intMapP1;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            int val = rand() % RANDOM_RANGE + 1;
            if (intMapP1.find(val) == intMapP1.end()) {
                intMapP1.insert(IntBool(val, true));
                intVec.push_back(val);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void insertToMapPattern2Random(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));
    for (int t = 0; t < samples ; ++t) {
        IntBoolMap intMapP2;
        IntVec intVec;
        intVec.reserve(test_size);

        auto start = std::chrono::steady_clock::now();

        for (int i = 0; i < test_size; ++i) {
            int val = rand() % RANDOM_RANGE + 1;
            if (intMapP2.insert(IntBool(val, true)).second) {
                intVec.push_back(val);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void interSectAfterSort(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));

    IntVec vec1;
    IntVec vec2;

    for (int i = 0; i < test_size; ++i) {
        int val = rand() % RANDOM_RANGE + 1;
        vec1.push_back(val);
        val = rand() % RANDOM_RANGE + 1;
        vec2.push_back(val);
    }


    for (int t = 0; t < samples ; ++t) {
        IntVec intVec;

        auto start = std::chrono::steady_clock::now();

        intVec.resize(test_size*2);
        std::sort (vec1.begin(), vec1.end());
        std::sort (vec2.begin(), vec2.end());

        IntVec::iterator it = std::set_intersection (vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), intVec.begin());
        intVec.resize(it - intVec.begin());
        std::sort (intVec.begin(), intVec.end());

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void interSetNoSort(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));

    IntVec vec1;
    IntVec vec2;

    for (int i = 0; i < test_size; ++i) {
        int val = rand() % RANDOM_RANGE + 1;
        vec1.push_back(val);
        val = rand() % RANDOM_RANGE + 1;
        vec2.push_back(val);
    }


    for (int t = 0; t < samples ; ++t) {
        IntVec intVec;

        auto start = std::chrono::steady_clock::now();

        IntSet intSet1;
        intSet1.insert(vec1.begin(), vec1.end());
        IntSet intSet2;
        intSet2.insert(vec2.begin(), vec2.end());
        intVec.resize(test_size*2);

        IntVec::iterator it = std::set_intersection (intSet1.begin(), intSet1.end(),
                intSet2.begin(), intSet2.end(), intVec.begin());
        intVec.resize(it - intVec.begin());

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}

void interSectVCLP(int samples, int test_size, TimesVector& times) {
    preExit(samples);
    srand (time(NULL));

    IntVec vec1;
    IntVec vec2;

    for (int i = 0; i < test_size; ++i) {
        int val = rand() % RANDOM_RANGE + 1;
        vec1.push_back(val);
        val = rand() % RANDOM_RANGE + 1;
        vec2.push_back(val);
    }

    for (int t = 0; t < samples ; ++t) {
        IntVec intVec;

        auto start = std::chrono::steady_clock::now();

        IntSet intSet;
        intSet.insert(vec1.begin(), vec1.end());
        for(auto v: vec2) {
            if (intSet.find(v) != intSet.end()) { // present in both
                intVec.push_back(v);
            }
        }

        auto finish = std::chrono::steady_clock::now();

        double elapsed_seconds = std::chrono::duration_cast<std::chrono::duration<double> >(finish - start).count();
        times.push_back(elapsed_seconds);
    }
}


#endif // TEST_ALGORITHMS_H
