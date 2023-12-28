algorithms = ["Selection Sort", "Insertion Sort", "Bubble Sort", "Shaker Sort", "Shell Sort", "Heap Sort", "Merge Sort", "Quick Sort", "Counting Sort", "Radix Sort", "Flash Sort"]

for algo in algorithms:
    temp = algo.split(" ")
    filename = temp[0].lower() + temp[1]
    header = temp[0].upper() + "_" + temp[1].upper()
    function_name = temp[0].lower() + temp[1]
    with open("SOURCE/algorithms/" + filename + ".hpp", "w") as f:
        f.write("#ifndef " + header + "_HPP\n")
        f.write("#define " + header + "_HPP\n")
        f.write("\n")
        f.write('#include "helpFunctions.hpp"\n')
        f.write("\n")
        f.write("void " + function_name + "(int array[], int n, long long &comparisons);\n")
        f.write("void " + function_name + "(int array[], int n);\n")
        f.write("\n")
        f.write("#endif // " + header + "_HPP")
        
    with open("SOURCE/algorithms/" + filename + ".cpp", "w") as f:
        f.write('#include "' + filename + '.hpp"\n')
        f.write("\n")
        f.write("void " + function_name + "(int array[], int n, long long &comparisons) {\n\n}\n")
        f.write("\n")
        f.write("void " + function_name + "(int array[], int n) {\n\n}")


with open("SOURCE/sort_execute.hpp", "w") as f:
    f.write("#include <iostream>\n")
    f.write("#include <chrono>\n\n")

    for algo in algorithms:
        temp = algo.split(" ")
        filename = temp[0].lower() + temp[1]
        f.write(f'#include "algorithms/{filename}.hpp"\n')
    f.write("\n")

    for i in range(len(algorithms)):
        temp = algorithms[i].split(" ")
        header = temp[0].upper() + "_" + temp[1].upper()
        f.write(f"#define {header} {i}")