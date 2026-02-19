#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void insertionSort_UEM243135(int uem2_arr[], int uem4_size)
{
    for (int uem1_j = 1; uem1_j < uem4_size; uem1_j++)
    {
        int uem3_key = uem2_arr[uem1_j];
        int uem1_i   = uem1_j - 1;

        while (uem1_i >= 0 && uem2_arr[uem1_i] > uem3_key)
        {
            uem2_arr[uem1_i + 1] = uem2_arr[uem1_i];
            uem1_i--;
        }
        uem2_arr[uem1_i + 1] = uem3_key;
    }
}

int main()
{
    cout << "Roll No: UEM243135" << endl;
    cout << "Insertion Sort - Time Analysis\n\n";

    int    uem2_testSizes[10] = {1000, 1500, 2500, 3500, 4500, 5500, 6500, 7500, 8500, 9500};
    double uem4_timings[10][10];

    for (int uem1_i = 0; uem1_i < 10; uem1_i++)
    {
        int uem4_n = uem2_testSizes[uem1_i];

        int *uem2_arr = new int[uem4_n];

        srand(time(0) + uem1_i);
        for (int uem1_k = 0; uem1_k < uem4_n; uem1_k++) {
            uem2_arr[uem1_k] = rand() % 1000 + 1;
        }

        double uem3_totalTime = 0;

        for (int uem1_iter = 0; uem1_iter < 10; uem1_iter++)
        {
            auto uem1_startTime = chrono::high_resolution_clock::now();

            insertionSort_UEM243135(uem2_arr, uem4_n);

            auto uem1_endTime = chrono::high_resolution_clock::now();

            chrono::duration<double, micro> uem1_duration = uem1_endTime - uem1_startTime;

            uem4_timings[uem1_i][uem1_iter] = uem1_duration.count();
            uem3_totalTime += uem1_duration.count();
        }

        double uem3_avgTime = uem3_totalTime / 10.0;

        cout << fixed << setprecision(4);
        cout << "Array Size: " << uem4_n
             << " | Average Time: " << uem3_avgTime << " microseconds\n\n";

        delete[] uem2_arr;
    }

    return 0;
}
