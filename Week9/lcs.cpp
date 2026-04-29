#include <iostream>
#include <string>
using namespace std;

// H&S DP: bottom-up table fill
// b[i][j] stores direction for traceback
// c[i][j] stores LCS length

int c[20][20];
char b[20][20];

void LCSLength(string x, string y, int m, int n) {
    for (int i = 1; i <= m; i++) c[i][0] = 0;
    for (int j = 0; j <= n; j++) c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i-1] == y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D'; // Diagonal
            } else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U'; // Up
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L'; // Left
            }
        }
    }
}

// H&S Traceback to print LCS
void printLCS(string x, int i, int j) {
    if (i == 0 || j == 0) return;
    if (b[i][j] == 'D') {
        printLCS(x, i-1, j-1);
        cout << x[i-1];
    } else if (b[i][j] == 'U') {
        printLCS(x, i-1, j);
    } else {
        printLCS(x, i, j-1);
    }
}

int main() {
    string x = "howwitxza";
    string y = "sahania";
    int m = x.length();
    int n = y.length();

    LCSLength(x, y, m, n);

    cout << "LCS Length : " << c[m][n] << endl;
    cout << "LCS String : ";
    printLCS(x, m, n);
    cout << endl;

    // Print DP Table
    cout << "\nDP Table:\n";
    cout << "    ";
    for (char ch : y) cout << ch << "  ";
    cout << endl;
    for (int i = 1; i <= m; i++) {
        cout << x[i-1] << " | ";
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << "  ";
        cout << endl;
    }

    return 0;
}
