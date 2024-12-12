#include <iostream>
using namespace std;

int i = 1;



void rtowerOfHanoi(int n, char src, char dest, char aux) {
	if (n == 1) {
		cout << " Move no. " << i++ << "," << i << " Move disk " << n << " From rod " << src << " to " << dest << " and then to " << aux << endl;
		i++;
		return;
	}

	rtowerOfHanoi(n - 1, src, dest, aux);

	cout << " Move no. " << i++ << " Move disk " << n << " From rod " << src << " to " << dest << endl;

	rtowerOfHanoi(n - 1, aux, dest, src);

	cout << " Move no. " << i++ << " Move disk " << n << " from rod " << dest << " to " << aux << endl;

	rtowerOfHanoi(n - 1, src, dest, aux);

}


int main() {
	int n;
	cin >> n;

	cout << "Tower of hanoi problem for " << n << " Disks: \n";
	rtowerOfHanoi(n, 'S', 'A', 'D');
	i--;

	cout << "Total number of moves: " << i << endl;

	return 0;
}
