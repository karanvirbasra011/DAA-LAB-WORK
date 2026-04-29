#include <iostream>
using namespace std;

int tips(double v, int t) {
    if (v >= 1) {
        t++;
        v = v - (0.425 * v);
        return tips(v, t);
    } else {
        return t;
    }
}

int main() {
    cout << tips(40, 0) << endl;
    return 0;
}
