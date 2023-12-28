#include <iostream>
#include <chrono>
#include <cstring>

#include "sort_execute.hpp"
#include "DataGenerator.hpp"
#include "helpler.hpp"
#include "Experiment.hpp"

void executeFromCommandLine(int &argv, char **&argc) {
    Experiment experiment;

    // check compare mode or algorithm mode
    if (strcmp(argc[1], "-c") == 0) {
        experiment.isCompareMode = true;
    }
    else if (strcmp(argc[1], "-a") == 0) {
        experiment.isCompareMode = false;
    }
    else {
        std::cout << "Invalid mode: only -a for algorithm mode and -c for compare mode\n";
        return;
    }

    // get input parameters
    if (experiment.isCompareMode) {
        experiment.algorithmID[0] = getAlgorithmID(argc[2]);
        experiment.algorithmID[1] = getAlgorithmID(argc[3]);

        experiment.isInputingFromFile = !is_number(argc[4]);
        if (experiment.isInputingFromFile) {
            std::string inputFileName = argc[4];
            experiment.filename = inputFileName;

            int readStatus = readArray(experiment.arrays[0], experiment.size, argc[4]);
            // if read fail (file not exists)
            if (readStatus == -1)
                exit(1);
        }
        else {
            experiment.size = atoi(argc[4]);

            experiment.dataOrderID = getDataOrderID(argc[5]);
            // dataOrder not exists
            if (experiment.dataOrderID == -1) {
                std::cout << "Wrong data order syntax\n";
                std::cout << "syntax: -rand, -sorted, -rev, -nsorted\n";
                return;
            }

            experiment.arrays[0] = new int[experiment.size];
            GenerateData(experiment.arrays[0], experiment.size, experiment.dataOrderID);
            char filename[] = "input.txt";
            writeData(experiment.arrays[0], experiment.size, filename);
        }
    }
    else {
        experiment.algorithmID[0] = getAlgorithmID(argc[2]);

        experiment.isInputingFromFile = !is_number(argc[3]);
        if (experiment.isInputingFromFile) {
            std::string inputFileName = argc[3];
            experiment.filename = inputFileName;

            int readStatus = readArray(experiment.arrays[0], experiment.size, argc[3]);
            // if read fail (file not exists)
            if (readStatus == -1)
                exit(1);
            
            experiment.outputParameter = getOutputParameterID(argc[4]);
        }
        else {
            experiment.size = atoi(argc[3]);

            experiment.isRunningAllDataOrder = isOutputParameterID(argc[4]);

            if (experiment.isRunningAllDataOrder) {
                experiment.outputParameter = getOutputParameterID(argc[4]);
                
                for (int dataOrder_id = 0; dataOrder_id < NUMBER_DATA_ORDER; dataOrder_id++) {
                    experiment.arrays[dataOrder_id] = new int[experiment.size];
                    GenerateData(experiment.arrays[dataOrder_id], experiment.size, dataOrder_id);
                    char filename[] = "input_0.txt";
                    filename[6] = dataOrder_id + 1 + '0';
                    writeData(experiment.arrays[dataOrder_id], experiment.size, filename);
                }
            }
            else {
                experiment.dataOrderID = getDataOrderID(argc[4]);
                experiment.outputParameter = getOutputParameterID(argc[5]);

                experiment.arrays[0] = new int[experiment.size];
                GenerateData(experiment.arrays[0], experiment.size, experiment.dataOrderID);
                char filename[] = "input.txt";
                writeData(experiment.arrays[0], experiment.size, filename);
            }
        }
    }

    if (experiment.isCompareMode) {
        experiment.compareMode();
    }
    else {
        experiment.algorithmMode();
    }

    experiment.printResult();
    return;
}

int main(int argv, char **argc) {
    executeFromCommandLine(argv, argc);
}