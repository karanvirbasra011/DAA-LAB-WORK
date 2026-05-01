#include <iostream>
#include <cmath>
using namespace std;

int x[100]; // x[i] = column position of queen in row i
// Check if placing queen at row k, column i is valid
bool Place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        // Check column conflict and diagonal conflict
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return false;
    }
    return true;
}
// Find all solutions for N-Queens
void NQueen(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                // Print one solution
                cout << "Solution: ";
                for (int j = 1; j <= n; j++)
                    cout << x[j] << " ";
                cout << endl;
            } else {
                NQueen(k + 1, n); // Recurse for next row
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    NQueen(1, n);
    return 0;
}
