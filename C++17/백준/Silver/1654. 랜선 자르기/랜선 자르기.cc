#include <iostream>
#include <vector>
using namespace std;

bool canMake(const unsigned int& len, const vector<unsigned int>& lenghts,
             int& N) {
    int cnt = 0;
    for (const unsigned int& ele : lenghts) {
        cnt += ele / len;
    }
    if (cnt >= N)
        return true;
    else
        return false;
}

int main() {
    int K, N;
    cin >> K >> N;

    vector<unsigned int> lenghts(K);
    unsigned int high = 0, low = 1, mid = 0;
    for (int i = 0; i < K; i++) {
        cin >> lenghts[i];
        if (high < lenghts[i]) high = lenghts[i];
    }

    while (high >= low) {
        mid = (high + low) / 2;
        if (canMake(mid, lenghts, N)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high;

    return 0;
}