#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include <chrono>
#include <cstring>
#include "helpler.hpp"
#include "sort_execute.hpp"
#include "DataGenerator.hpp"

#define MAX_SIZE 1000000

class Result {
    public:
        std::chrono::duration<double, std::milli> running_time;
        long long comparisons;
};

class Experiment {
    public:
        int **arrays;
        int size;
        std::string filename;
        bool isCompareMode;
        bool isInputingFromFile;
        int algorithmID[2];
        int dataOrderID;
        bool isRunningAllDataOrder;
        Result* results;
        int outputParameter;

        Experiment();
        ~Experiment();
        void compareMode();
        void algorithmMode();

        void printResult();
};

#endif // EXPERIMENT_HPP