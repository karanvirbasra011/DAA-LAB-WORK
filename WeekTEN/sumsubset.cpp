#include<iostream>
#include<chrono>
#include<cstdlib>
#include<sstream>
using namespace std;
using namespace std::chrono;

void findSubsets(int idx, int currSum, int count, int nums[], int sz, int target, int path[]){
    if(currSum == target){
        for(int i = 0; i < count; i++) cout << path[i] << " ";
        cout << endl;
        return;
    }
    if(idx == sz || currSum > target) return;

    path[count] = nums[idx];
    findSubsets(idx + 1, currSum + nums[idx], count + 1, nums, sz, target, path);
    findSubsets(idx + 1, currSum, count, nums, sz, target, path);
}

int main(){
    int lo = 5, hi = 25, gap = 1, runs = 3;
    for(int i = lo; i <= hi; i+=gap){
        int *nums = new int[i];
        for(int k = 0; k < i; k++) nums[k] = (rand() % 20) + 1;
        int target = 0;
        for(int k = 0; k < i; k++) target += nums[k];
        target /= 3; // target is ~1/3 of total sum
        int path[100];
        long long elapsed = 0;
        for(int j = 1; j <= runs; j++){
            streambuf* oldBuf = cout.rdbuf();
            ostringstream nullStream;
            cout.rdbuf(nullStream.rdbuf());
            auto t1 = system_clock::now();
            findSubsets(0, 0, 0, nums, i, target, path);
            auto t2 = system_clock::now();
            cout.rdbuf(oldBuf);
            elapsed += duration_cast<nanoseconds>(t2-t1).count();
        }
        cout<<"Time for "<<i<<" elements : "<<elapsed/runs<<"   nanoseconds "<<endl;
        delete[] nums;
    }
    return 0;
}
