#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<float> scores(N);
    
    for(int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    
    int maxScore = scores[0];
    
    for(const auto& ele : scores) {
        if (maxScore < ele) maxScore = ele;
    }
    
    float sum = 0;
    for(auto& ele : scores) {
        ele = ele/maxScore*100;
        sum += ele;
    }
    
    cout << sum/N;
    return 0;
}