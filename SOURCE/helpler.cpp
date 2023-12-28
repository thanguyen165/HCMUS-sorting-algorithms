#include "helpler.hpp"

int readArray(int *&arr, int &size, char *fileName) {
    if (arr != nullptr) {
        delete[] arr;
        arr = nullptr;
    }
    
    FILE *fp = fopen(fileName, "r");
    if (fp == nullptr) {
        printf("Error: File not found\n");
        return -1;
    }

    fscanf(fp, "%d", &size);
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
    return 0;
}

int writeData(int *&arr, int &size, char *fileName) {
    FILE *fp = fopen(fileName, "w");
    if (fp == nullptr) {
        printf("Error: File not found\n");
        return -1;
    }

    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);
    return 0;
}

bool is_number(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return false;
    }
    return true;

}

int getOutputParameterID(char *flag) {
    if (strcmp(flag, "-time") == 0) return 1;
    if (strcmp(flag, "-comp") == 0) return 2;
    if (strcmp(flag, "-both") == 0) return 3;
    return -1;
}

bool isOutputParameterID(char *flag) {
    return (getOutputParameterID(flag) != -1);
}