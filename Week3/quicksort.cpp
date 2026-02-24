#include <iostream>
#include <vector>
using namespace std;

void swapElements(vector<int> &array, int firstIndex, int secondIndex) {
    int temporaryValue = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temporaryValue;
}

int partition(vector<int> &array, int lowerBound, int upperBound) {
    int pivotValue = array[upperBound];
    int smallerElementIndex = lowerBound - 1;

    for (int currentIndex = lowerBound; currentIndex <= upperBound - 1; currentIndex++) {
        if (array[currentIndex] < pivotValue) {
            smallerElementIndex++;
            swapElements(array, smallerElementIndex, currentIndex);
        }
    }

    swapElements(array, smallerElementIndex + 1, upperBound);
    return smallerElementIndex + 1;
}

void quickSort(vector<int> &array, int lowerBound, int upperBound) {
    if (lowerBound < upperBound) {
        int pivotFinalPosition = partition(array, lowerBound, upperBound);

        quickSort(array, lowerBound, pivotFinalPosition - 1);
        quickSort(array, pivotFinalPosition + 1, upperBound);
    }
}

int main() {
    vector<int> array = {10, 9, 10, 20, 20};
    int totalElements = array.size();

    quickSort(array, 0, totalElements - 1);

    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
