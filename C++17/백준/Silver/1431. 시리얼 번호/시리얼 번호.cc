#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    size_t n;
    cin >> n;

    std::vector<string> guitars(n);

    for (int i = 0; i < n; i++) {
        cin >> guitars[i];
    }

    sort(guitars.begin(), guitars.end(), [](const string& a, const string& b) {
        if (a.size() == b.size()) {
            int a_sum = 0;
            int b_sum = 0;
            for (const auto& c : a) {
                if (isdigit(c)) {
                    a_sum += c - '0';
                }
            }
            for (const auto& c : b) {
                if (isdigit(c)) {
                    b_sum += c - '0';
                }
            }
            if (a_sum == b_sum) {
                return a < b;
            }
            return a_sum < b_sum;
        }
        return a.size() < b.size();
    });

    for (const auto& guitar : guitars) {
        cout << guitar << '\n';
    }

    return 0;
}