#include <iostream>

int main() {
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;
    int pots[n];
    int foo[n/a];
    int days = 0;
    for(int i = 0; i < n; i++) pots[i] = k;
    for(int i = 0; i < n/a; i++) foo[i] = n/(n/a)*i;
    int bar = 0;
    
    while(1) {
        int die = 0;
        if(bar >= n/a) bar = 0;
        for(int i = 0; i < a; i++) {pots[i+foo[bar]]+=b;}
        for(int i = 0; i < n; i++) {
            pots[i]--;
            if(pots[i]==0) {
                die = 1;
                break;
            }
        }
        days++; bar++;
        if(die==1) break;
    }

    std::cout << days << std::endl;
    return 0;
}