#include <iostream>

using namespace std;

int main() {
	int num1 = 1, num2 = 0, reg = 0, n;
	cout << "Enter number of fibonacci numbers to compute: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		reg = num1 + num2;
		num2 = num1;
		num1 = reg;
		cout << reg << " ",'\n';
	}
}
