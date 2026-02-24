#include <iostream>
using namespace std;

void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    int leftSize = midIndex - leftIndex + 1;
    int rightSize = rightIndex - midIndex;

    int leftSubArray[leftSize], rightSubArray[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftSubArray[i] = array[leftIndex + i];
    for (int j = 0; j < rightSize; j++)
        rightSubArray[j] = array[midIndex + 1 + j];

    int leftPointer = 0, rightPointer = 0, mergedIndex = leftIndex;

    while (leftPointer < leftSize && rightPointer < rightSize) {
        if (leftSubArray[leftPointer] <= rightSubArray[rightPointer]) {
            array[mergedIndex] = leftSubArray[leftPointer];
            leftPointer++;
        } else {
            array[mergedIndex] = rightSubArray[rightPointer];
            rightPointer++;
        }
        mergedIndex++;
    }

    while (leftPointer < leftSize) {
        array[mergedIndex] = leftSubArray[leftPointer];
        leftPointer++;
        mergedIndex++;
    }

    while (rightPointer < rightSize) {
        array[mergedIndex] = rightSubArray[rightPointer];
        rightPointer++;
        mergedIndex++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(array, leftIndex, midIndex);
        mergeSort(array, midIndex + 1, rightIndex);
        merge(array, leftIndex, midIndex, rightIndex);
    }
}

int main() {
    int totalElements;
    cout << "Enter the number of elements: ";
    cin >> totalElements;

    int array[totalElements];
    cout << "Enter " << totalElements << " elements: ";
    for (int i = 0; i < totalElements; i++) {
        cin >> array[i];
    }

    mergeSort(array, 0, totalElements - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < totalElements; i++)
        cout << array[i] << " ";
    cout << endl;

    return 0;
}
