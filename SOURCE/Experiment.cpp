#include "Experiment.hpp"

Experiment::Experiment() {
    arrays = new int*[NUMBER_DATA_ORDER];
    for (int i = 0; i < NUMBER_DATA_ORDER; i++) {
        arrays[i] = nullptr;
    }
    size = -1;

    results = new Result[NUMBER_DATA_ORDER];
}

Experiment::~Experiment() {
    for (int i = 0; i < NUMBER_DATA_ORDER; i++) {
        delete[] arrays[i];
    }
    delete[] arrays;
    size = -1;
    delete[] results;
}

void Experiment::compareMode() {
    int *arr = arrays[0];
    int *tmp = new int[size];

    for (int i = 0; i < 2; i++) {
        memcpy(tmp, arr, size * sizeof(int));
        sort(tmp, size, algorithmID[i], results[i].running_time);

        memcpy(tmp, arr, size * sizeof(int));
        sort(tmp, size, algorithmID[i], results[i].comparisons); 
    }

    char filename[] = "output.txt";
    writeData(tmp, size, filename);
    delete[] tmp;
    return;
}

void Experiment::algorithmMode() {
    int* tmp = new int[size];

    int times = isRunningAllDataOrder ? NUMBER_DATA_ORDER : 1;
    for (int i = 0; i < times; i++) {
        if (outputParameter == 3) {
            memcpy(tmp, arrays[i], size * sizeof(int));
            sort(tmp, size, algorithmID[0], results[i].comparisons);
            memcpy(tmp, arrays[i], size * sizeof(int));
            sort(tmp, size, algorithmID[0], results[i].running_time);
        }
        else if (outputParameter == 2) {
            memcpy(tmp, arrays[i], size * sizeof(int));
            sort(tmp, size, algorithmID[0], results[i].comparisons);
        }
        else if (outputParameter == 1) {
            memcpy(tmp, arrays[i], size * sizeof(int));
            sort(tmp, size, algorithmID[0], results[i].running_time);
        }
    }

    char filename[] = "output.txt";
    writeData(tmp, size, filename);
    delete[] tmp;
    return;
}

void Experiment::printResult() {
    if (isCompareMode) {
        std::cout << "COMPARE MODE\n";

        std::cout << "Algorithm: " << getAlgorithmName(algorithmID[0]) << " | " << getAlgorithmName(algorithmID[1]) << "\n";

        if (isInputingFromFile) {
            std::cout << "Input file: " << filename << "\n";
        }
        std::cout << "Input size: " << size << "\n";
        if (!isInputingFromFile) {
            std::cout << "Input order: ";
            std::cout << getDataOrderName(dataOrderID);
            std::cout << "\n";
        }

        std::cout << "---------------------------------------------\n";
        std::cout << "Running time: " << results[0].running_time.count() << " | " << results[1].running_time.count() << "\n";
        std::cout << "Comparisons: " << results[0].comparisons << " | " << results[0].comparisons << "\n";
    }
    else {
        std::cout << "ALGORITHM MODE\n";

        std::cout << "Algorithm: " << getAlgorithmName(algorithmID[0]) << "\n";

        if (isInputingFromFile) {
            std::cout << "Input file: " << filename << "\n";
        }
        std::cout << "Input size: " << size << "\n";
        int times = isRunningAllDataOrder ? NUMBER_DATA_ORDER : 1;
        for (int dataOrder_id = 0; dataOrder_id < times; dataOrder_id++) {
            if (!isInputingFromFile) {
                std::cout << "Input order: ";
                std::cout << getDataOrderName(dataOrder_id);
                std::cout << "\n";
            }

            std::cout << "---------------------------------------------\n";
            if (outputParameter == 3) {
                std::cout << "Running time: " << results[dataOrder_id].running_time.count() << "\n";
                std::cout << "Comparisons: " << results[dataOrder_id].comparisons << "\n";
            }
            else if (outputParameter == 2) {
                std::cout << "Comparisons: " << results[dataOrder_id].comparisons << "\n";
            }
            else {
                std::cout << "Running time: " << results[dataOrder_id].running_time.count() << "\n";
            }
        }
    }

    return;
}