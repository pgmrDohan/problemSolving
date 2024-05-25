#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pos = 0;
    int time = 0;
    int N, K;
    cin >> N >> K;

    vector<int> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i];
    }
    if (N == K) {
        cout << 0;
        return 0;
    }
    sort(lectures.begin(), lectures.end());

    if (K == 0) {
        for (const auto& ele : lectures) {
            time += ele - pos;
            pos = ele;
        }
        cout << time;
        return 0;
    }

    vector<array<int, 2>> distances(N);
    for (int i = 0; i < N; i++) {
        const auto& ele = lectures[i];
        int distance = ele - pos;
        pos = ele;
        array<int, 2> dis_i = {distance, ele};
        distances[i] = dis_i;
    }
    sort(distances.begin(), distances.end(),
         [](const array<int, 2>& a, const array<int, 2>& b) {
             return a[0] > b[0];
         });

    vector<int> skip_idx(K);
    for (int i = 0; i < K; i++) {
        skip_idx[i] = distances[i][1];
    }
    sort(skip_idx.begin(), skip_idx.end());

    pos = 0;

    for (const int& ele : lectures) {
        if (ele == skip_idx[0]) {
            pos = ele;
            skip_idx.erase(skip_idx.begin());
        } else {
            time += ele - pos;
            pos = ele;
        }
    }
    cout << time;
    return 0;
}