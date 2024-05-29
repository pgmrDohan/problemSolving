#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 1) {
        cout << 666;
        return 0;
    }

    N--;
    vector<int> no = {0, 666};
    int cnt = 0;
    bool sixMode = false;
    int sixModeNum = 0;
    int sixcnt = 0;

    while (cnt != N) {
        if (!sixMode) {  // 16
            no[0]++;
            if (no[0] % 10 == 6) {
                for (int i = log10(no[0]); i >= 0; i--) {
                    if (to_string(no[0])[i] == '6') {
                        sixcnt++;  // 1
                    } else {
                        break;
                    }
                    try {
                        no.at(1 + sixcnt) = 0;
                    } catch (const out_of_range& ex) {
                        no.push_back(0);
                    }
                }
                if (no.size() - 1 != 1 + sixcnt) {
                    for (int i = 0; i < no.size() - 1 - 1 - sixcnt; i++) {
                        no.erase(no.begin() + 1 + sixcnt,
                                 no.begin() + (no.size() - 1));
                    }
                }
                no.at(1 + sixcnt) = 0;
                sixModeNum = no[0];
                no[0] /= pow(10, sixcnt);  // 1 666 0
                sixMode = true;
            }
        } else {
            for (int i = 1; i <= no.size() - 3; i++) {
                no[1 + i] = 0;
            }
            no[1 + no.size() - 2]++;

            if (no[1 + no.size() - 2] % 10 != 0) {
                for (int i = 1; i <= log10(no[1 + no.size() - 2]); i++) {
                    no[1 + i] = -1;
                }
            }
            if (no[1 + no.size() - 2] == pow(10, sixcnt)) {
                sixMode = false;
                no[0] = ++sixModeNum;
                for (int i = 1; i <= no.size() - 2; i++) {
                    no[1 + i] = -1;
                }
                sixcnt = 0;
            }
        }
        if (no[0] == 0) no[0] = -1;
        cnt++;
    }

    string ans;
    for (const int& ele : no) {
        ans += ele < 0 ? "" : to_string(ele);
    }

    cout << ans;
}