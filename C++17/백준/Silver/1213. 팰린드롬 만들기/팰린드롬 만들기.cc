#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string name;
    cin >> name;
    int len = name.length();
    if (len == 1) {
        cout << name << endl;
        return 0;
    }
    sort(name.begin(), name.end());
    int cnt = 0;
    auto bar = name[0];
    int foo = 0;
    name.append("0");
    for (auto ele : name) {
        if (bar == ele) {
            foo++;
        } else {
            if (foo % 2 != 0) {
                cnt++;
            }
            bar = ele;
            foo = 1;
        }
    }
    bar = name[0];
    foo = 0;
    for (auto ele : name) {
        if (bar == ele) {
            foo++;
        } else {
            if (foo % 2 != 0) {
                break;
            }
            bar = ele;
            foo = 1;
        }
    }
    name.pop_back();
    if (name.length() % 2 == 0 && !cnt) {
        string ans;
        int idx = 0;
        for (int i = 0; i < name.length(); i += 2) {
            ans.insert(idx, 1, name[i]);
            ans.insert(idx++, 1, name[i]);
        }
        ans.resize(len);
        cout << ans << endl;
    } else if (name.length() % 2 != 0 && cnt == 1) {
        name.erase(name.find(bar, 0), 1);
        string ans;
        int idx = 0;
        for (int i = 0; i < name.length(); i += 2) {
            ans.insert(idx, 1, name[i]);
            ans.insert(idx++, 1, name[i]);
        }
        ans.insert(idx, 1, bar);
        ans.resize(len);
        cout << ans << endl;
    } else {
        cout << "I'm Sorry Hansoo" << endl;
    }

    return 0;
}