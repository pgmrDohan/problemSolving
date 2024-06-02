#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    stack<int> st;
    vector<char> ans;
    int popedCnt = 0;
    int starti = 1;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    while (popedCnt <= n - 1) {
        if (starti > nums[popedCnt]) {
            cout << "NO";
            return 0;
        }
        for (int i = starti; i <= nums[popedCnt]; i++) {
            st.push(i);
            ans.push_back('+');
        }
        if (st.empty()) continue;
        starti = nums[popedCnt] + 1;
        st.pop();
        ans.push_back('-');
        popedCnt++;
        while (!st.empty() && nums[popedCnt] == st.top()) {
            st.pop();
            ans.push_back('-');
            popedCnt++;
            if (popedCnt == n) break;
        }
    }

    for (const char& ele : ans) {
        cout << ele << '\n';
    }

    return 0;
}