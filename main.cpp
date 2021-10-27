#include <random>
#include <iostream>
#include <time.h>
#include <fstream>
#include <string>

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void genRandDataFile(std::string fileName, int numGenerate, int numRange);
int * readData(std::string fileName, int size);

int main() {
    const int SIZE1 = 1000, SIZE2 = 10000, SIZE3 = 100000;
    const int RAND_RANGE = 100000;
    //clock_t start = clock();
    //int dataArray[SIZE1];
    int* dataArray;
    genRandDataFile("randomData100000.txt", SIZE3, RAND_RANGE);
    dataArray = readData("randomData100000.txt", SIZE3);
    //readData("randomData1000.txt", dataArray[SIZE1]);
    std::cout << "Size of array: " << sizeof(dataArray) / sizeof(dataArray[0]) << std::endl;

    srand(time(0));
    
    
    int test[] = {4, 12, 6, 50, 2, 1, 90, 40, 17, 4};
    //selectionSort(test, sizeof(test) / sizeof(test[0]));
    //bubbleSort(dataArray, sizeof(dataArray) / sizeof(dataArray[0]));
    mergeSort(dataArray, 0, sizeof(dataArray) / sizeof(dataArray[0]));
    
    /*
    for (int i = 0; i < sizeof(test)/sizeof(test[0]); i++) {
        std::cout << "Index " << i << ": " << test[i] << std::endl;
    }*/

    for (int i = 0; i < sizeof(dataArray)/sizeof(dataArray[0]); i++) {
        std::cout << "Index " << i << ": " << dataArray[i] << std::endl;
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
        for (int j = i + 1; j < size; j++) {
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


void mergeSort(int arr[], int left, int right) {
    static int numCompare = 0;
    int mid;
    if (right > left) {
        mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);

        numCompare++;
    }
}

void merge(int arr[], int left, int mid, int right) {
    static int numCompare = 0, numSwap = 0;
    int subArrSize1 = mid - left + 1, subArrSize2 = right - mid;
    int indexSubArr1 = 0, indexSubArr2 = 0, indexMerged = left;
    int leftArr[subArrSize1], rightArr[subArrSize2];

    for (int i = 0; i < subArrSize1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < subArrSize2; i++) {
        rightArr[i] = arr[mid + i + 1];
    }

    // Compares entries in sub arrays
    while (indexSubArr1 < subArrSize1 && indexSubArr2 < subArrSize2) {
        if (leftArr[indexSubArr1] <= rightArr [indexSubArr2]) {
            arr[indexMerged] = leftArr[indexSubArr1];
            indexSubArr1++;
        }
        else {
            arr[indexMerged] = rightArr[indexSubArr2];
            indexSubArr2++;
        }
        indexMerged++;
        numCompare++;
        numSwap++;
    }

    // Adds remaining in left subArr
    while (indexSubArr1 < subArrSize1) {
        arr[indexMerged] = leftArr[indexSubArr1];
        indexMerged++;
        indexSubArr1++;
        numSwap++;
    }

    // Adds remaining in right subArr
    while (indexSubArr1 < subArrSize1) {
        arr[indexMerged] = rightArr[indexSubArr2];
        indexMerged++;
        indexSubArr2++;
        numSwap++;
    }
}

void genRandDataFile(std::string fileName, int numGenerate, int numRange) {
    std::ofstream ranDataFile;
    ranDataFile.open(fileName);

    for (int i = 0; i < numGenerate; i++) {
        ranDataFile << rand() % numRange << std::endl;
    }
    ranDataFile.close();
}

int * readData(std::string fileName, int size) {
    std::ifstream readFile;
    readFile.open(fileName);
    int tempInt, i = 0;
    int arr[size];

    while (readFile >> arr[i]) {
        //arr[i] = tempInt;
        //std::cout << "Value in temp " << i << ": "<< arr[i] << std::endl;
        i++;
    }

    return arr;
}