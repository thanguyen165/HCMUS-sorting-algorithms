#ifndef DATA_GENERATOR_HPP
#define DATA_GENERATOR_HPP

#define NUMBER_DATA_ORDER 4

void GenerateData(int a[], int n, int dataType = 0);
std::string getDataOrderName(int data_order_id);
int getDataOrderID(char *str);

#endif // DATA_GENERATOR_HPP