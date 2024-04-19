// Kiet Nguyen
// CECS 325-02 Prog 3
// Prog 2 - Sorting Contest
// Due 3/12/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace ::std;

void bubble(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3) // Checking for three command line arguments
    {
        cout << "Error: Please enter a input.txt file & an output.txt file.\n";
        exit(1);
    }

    int index = 0;
    int capacity = 10;              // Initial size for dynamic array
    int *array = new int[capacity]; // Dynamic Array

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    if (!inputFile.is_open())
    {
        cout << "ERROR: Unable to open input file.\n";
        exit(1);
    }
    else if (!outputFile.is_open())
    {
        cout << "ERROR: Unable to open output file.\n";
        exit(1);
    }

    int number;
    while (inputFile >> number)
    {
        if (index == capacity)
        {
            capacity *= 2;
            int *newArray = new int[capacity];
            for (int i = 0; i < index; i++)
            {
                newArray[i] = array[i];
            }
            delete[] array; // Deallocating dynamic array from heap
            array = newArray;
        }
        array[index++] = number;
    }

    bubble(array, index - 1);
    for (int i = 0; i < index; i++)
    {
        outputFile << array[i] << endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}