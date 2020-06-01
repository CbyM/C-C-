#include <iostream>
using namespace std;

int main() {
	float x, salary, d, totalC = 0, left;

	cout << "enter salary: ";
	cin >> salary;
	cout << "enter costs to compute : ";

	while (cin >> x) {
		if (x == 00) {
			break;
		}
		else {
			totalC += x;
			left = salary - totalC;
			d = (left / salary) * 100;

			cout << "Percentage of salary left: " << d << "%" << "(" << left << "EUR)" << '\n';
			cout << "Percentage of salary spent: " << 100 - d << "%" << '\n';
		}


	}

	cout << "You have exited the program" << endl;


}