#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	string n;
	while(1) {
		cin >> n;
		if(n == "0") break;
		int flag = 0;
		for(int i = 0; i < floor(n.length()/2); i++) {
			if(n[i] != n[n.length()-i-1]) {
				flag = 1;
			}
		}
		if(flag == 0) {
			cout << "yes" << '\n';
		} else {
			cout << "no" << '\n';
		}
	}
	
	return 0;
}