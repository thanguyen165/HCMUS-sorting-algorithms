#include <iostream>
#include <chrono>
#include <cstring>

#include "sort_execute.hpp"
#include "DataGenerator.hpp"
#include "helpler.hpp"

#define DEBUG

#define MAX_SIZE 500000
#define NUMBER_DATASIZE_TESTS 6

void overview(int* arr, int* arr2, bool isWritingToFile) {
    int DATA_SIZE_TESTS[6] = {10000, 30000, 50000, 100000, 300000, 500000};

    for (int dataOrderCode = 0; dataOrderCode < NUMBER_DATA_ORDER; dataOrderCode++) {       
        std::cout << "Data order: ";
        std::cout << getDataOrderName(dataOrderCode);
        std::cout << "\n";

        for (int size_idx = 0; size_idx < NUMBER_DATASIZE_TESTS; size_idx++) {
            int N = DATA_SIZE_TESTS[size_idx];

                #ifdef DEBUG
                N /= 1000;
                #endif

            std::cout << "Datasize: " << N << "\n";

            GenerateData(arr, N, dataOrderCode);

            long long comparisons = 0;
            std::chrono::duration<double, std::milli> running_time;

            for (int algorithmID = 0; algorithmID < NUMBER_SORT_ALGORITHM; algorithmID++) {
                // for stdout
                char separator = ' ';
                if (isWritingToFile) {
                    separator = ',';
                    std::cerr << dataOrderCode << " " << size_idx << " " << N << " " << algorithmID << "\n";
                }
                
                std::cout << getAlgorithmName(algorithmID);
                std::cout << separator;

                memcpy(arr2, arr, N * sizeof(int));
                sort(arr2, N, algorithmID, running_time);
                memcpy(arr2, arr, N * sizeof(int));
                sort(arr2, N, algorithmID, comparisons);
                
                std::cout << "Comparisons:" << separator << comparisons << separator;
                std::cout << "Running time (ms):" << separator << running_time.count();
                std::cout << "\n";
            }
        }
    }
}

int main(int argv, char** argc) {
    bool isWritingToFile = false;
    if (argv == 2) {
        char filename[50];
        freopen(argc[1], "w", stdout);
        isWritingToFile = true;
    }

    int* arr = new int[MAX_SIZE];
    int* arr2 = new int[MAX_SIZE];

    overview(arr, arr2, isWritingToFile);

    delete[] arr;
    delete[] arr2;
    return 0;
}