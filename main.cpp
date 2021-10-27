#include <random>
#include <iostream>
#include <time.h>
#include <fstream>

void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    clock_t start = clock();

    srand(time(0));
    int SIZE = 100, RAND_RANGE = 100000;
    int dataArray[SIZE];
    for (int i = 0; i < sizeof(dataArray)/ sizeof(dataArray[0]); i++) {
        dataArray[i] = rand() % RAND_RANGE;
    }
    
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
    static int numCompare = 0;
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
    }

    // Adds remaining in left subArr
    while (indexSubArr1 < subArrSize1) {
        arr[indexMerged] = leftArr[indexSubArr1];
        indexMerged++;
        indexSubArr1++;
    }

    // Adds remaining in right subArr
    while (indexSubArr1 < subArrSize1) {
        arr[indexMerged] = rightArr[indexSubArr2];
        indexMerged++;
        indexSubArr2++;
    }
}