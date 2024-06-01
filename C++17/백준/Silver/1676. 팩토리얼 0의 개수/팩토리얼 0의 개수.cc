#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 0, e = 0, o = 0;
    cin >> n;
    // 2 3 4 5 6 7 8 9 10
    for (int i = 2; i <= n; i++) {
        int foo = i;
        while (foo % 2 == 0) {
            e++;
            foo /= 2;
        }
        foo = i;
        while (foo % 5 == 0) {
            o++;
            foo /= 5;
        }
    }
    int ans = (e <= o) ? e : o;
    cout << ans;
}