#include <random>
#include <iostream>
#include <time.h>
#include <fstream>

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right, int arrFinal[]);


int main() {
    clock_t start = clock();

    static const int SIZE = 1000, RAND_RANGE = 100000;
    int dataArray[SIZE];
    for (int i = 0; i < sizeof(dataArray)/ sizeof(dataArray[0]); i++) {
        //dataArray[i] = rand % RAND_RANGE;
    }
    
    int test[] = {4, 12, 6, 50, 2, 1, 90, 40, 17, 4};
    selectionSort(test, sizeof(test) / sizeof(test[0]));
    bubbleSort(test, sizeof(test) / sizeof(test[0]));
    mergeSort(test, 0, sizeof(test) / sizeof(test[0]-1));

    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        std::cout << "Index " << i << ": " << test[i] << std::endl;
        }

    return 0;
}

void bubbleSort(int arr[], int size) {
    int tempVal;
    int numSwap = 0, numCompare = 0;

    for (int i = 0; i < size - 1; i++) {

        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[i]) {
                tempVal = arr[j];
                arr[j] = arr[i];
                arr[i] = tempVal;

                numSwap++;
                numCompare++;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex, j, i;
    int tempInt;
    int numSwap = 0, numCompare = 0;

    for (int i = 0; i < size - 1; i++) {

        minIndex = i;
        for (int j = i + 1; j < size-1; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                
                numCompare++;
            }
        }
        tempInt = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tempInt;

        numSwap++;
    }
}


void mergeSort(int arr[], int left, int right, int arrFinal[]) {
    int mid;
    if (right > left) {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
    }
}

void merge(int arr[]. int left, int mid, int right, int arrFinal[]) {
    for (int i = left; i < right; i++) {
        
    }
}