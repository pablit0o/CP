#include <iostream>
using namespace std;
 
int main() {
	long long k, n, w;
	cin >> k >> n >> w;
 
	long long total_price = 0;
	for (long long i = 1; i < w + 1; i++) {
		total_price += (i * k);
	}
	long long amount_needed =  total_price - n;
 
	if (amount_needed < 0) {
		amount_needed = 0;
	}
	cout << amount_needed;
}
