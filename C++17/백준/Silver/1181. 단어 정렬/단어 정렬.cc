#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> words(N);
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }
    
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    });
    
    words.erase(unique(words.begin(), words.end()),words.end());
    
    for(const auto& ele : words) {
        cout << ele << '\n';
    }
    
    return 0;
}