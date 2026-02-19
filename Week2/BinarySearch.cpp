#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

long long binarySearch_UEM243135(long long uem2_arr[], long long uem1_low, long long uem4_high, long long uem3_target)
{
    if (uem1_low > uem4_high) return -1;

    long long uem1_mid = (uem1_low + uem4_high) / 2;

    if (uem2_arr[uem1_mid] == uem3_target) return uem1_mid;
    else if (uem2_arr[uem1_mid] > uem3_target) return binarySearch_UEM243135(uem2_arr, uem1_low, uem1_mid - 1, uem3_target);
    else return binarySearch_UEM243135(uem2_arr, uem1_mid + 1, uem4_high, uem3_target);
}

int main()
{
    cout << "Roll No: UEM243135" << endl;
    cout << "Binary Search - Time Analysis\n\n";

    // UEM2 - array sizes | UEM4 - size count = 10
    long long uem2_testSizes[10] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000};
    double   uem4_timings[10][10];

    srand(time(0));

    for (long long uem1_i = 0; uem1_i < 10; uem1_i++)
    {
        long long uem4_n = uem2_testSizes[uem1_i];

        // UEM2 - dynamic plain array (no vectors)
        long long *uem2_arr = new long long[uem4_n];

        for (long long uem1_k = 0; uem1_k < uem4_n; uem1_k++) {
            uem2_arr[uem1_k] = rand() % 1000 + 1;
        }

        sort(uem2_arr, uem2_arr + uem4_n);

        double   uem3_totalTime = 0;
        long long uem1_result   = 0;

        for (long long uem1_iter = 0; uem1_iter < 10; uem1_iter++)
        {
            auto uem1_startTime = chrono::high_resolution_clock::now();

            uem1_result = binarySearch_UEM243135(uem2_arr, 0, uem4_n - 1, uem2_arr[0]);

            auto uem1_endTime = chrono::high_resolution_clock::now();

            chrono::duration<double, micro> uem1_duration = uem1_endTime - uem1_startTime;

            uem4_timings[uem1_i][uem1_iter] = uem1_duration.count();
            uem3_totalTime += uem1_duration.count();
        }

        if (uem1_result == -1) {
            cout << "Element not found" << endl;
        } else {
            cout << "Element found at index: " << uem1_result << endl;
        }

        double uem3_avgTime = uem3_totalTime / 10.0;

        cout << fixed << setprecision(4);
        cout << "Array Size: " << uem4_n
             << " | Average Time: " << uem3_avgTime << " microseconds\n\n";

        delete[] uem2_arr;
    }

    return 0;
}
