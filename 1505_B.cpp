/**
 *	Author: Nachiket Kanore
 *	Created: Wednesday 07 April 2021 07:52:44 PM IST
**/
#include <iostream>
using namespace std;

int SOD(int n) { return n < 10 ? n : n%10 + SOD(n/10); }

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while ((n = SOD(n)) > 9);
	cout << n;
}
