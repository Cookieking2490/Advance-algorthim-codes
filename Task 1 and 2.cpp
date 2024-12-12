#include <iostream>
#include <iostream>
#include <algorithm>
using namespace std;


//Task 1
//bool Anagrams(string s1, string s2) {
//	if (s1.size() != s2.size()) {
//		return false;
//	}
//
//	sort(s1.begin(), s1.end());
//	sort(s2.begin(), s2.end());
//
//	return s1 == s2;
//}
//
//int main()
//{
//	string s1, s2;
//	cin >> s1;
//	cin >> s2;
//
//	if (Anagrams(s1, s2)) {
//		cout << "The two words are anagrams" << endl;
//	}
//	else {
//		cout << "The two words are not anagrams" << endl;
//	}
//}

//Task 2

int main() {

	int c1, c2, c3;
	cin >> c1 >> c2 >> c3;

	if (c1 == c2) {
		if (c1 > c3) {
			cout << "Fake coin is lighter";
		}
		else if (c1 < c3) {
			cout << "Fake coin is heavier";
		}
		else {
			cout << "Wrong input";
		}
	}
	else if (c2 == c3) {
		if (c2 > c1) {
			cout << "Fake coin is lighter";
		}
		else if(c2 < c1) {
			cout << "Fake coin is heavier";
		}
		else {
			cout << "Wrong input";
		}
	}
	else if (c3==c1) {
		if (c3 > c2) {
			cout << "Fake coin is lighter";
		}
		else if (c3 < c2){
			cout << "Fake coin is heavier";
		}
		else {
			cout << "Wrong input";
		}
	}
	
	

}