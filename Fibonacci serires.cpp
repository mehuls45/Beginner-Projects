#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
	int N;
	cout << "Enter the N : ";
	cin >> N;
	ull f0 = 0, f1 = 1;
	ull f = f1;
	cout << "The Sequence of Fibonacci Numbers : " << endl;
	cout << f0 << " ";
	cout << f1 << " ";

	for(int i = 1; i < N; i++) {
		cout << f << " ";
		f0 = f1;
		f1 = f;
		f = f0 + f1;
	}
	cout << endl;
	return 0;
}
