#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

void textWrap(const vector<string> words, int lw) {
	int n = words.size();

	vector<vector<int>> extraSpaces(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		extraSpaces[i][i] = lw - words[i].length();
		for (int j = i + 1; j < n; j++) {
			extraSpaces[i][j] = extraSpaces[i][j - 1] - words[j].length()-1;
		}

	}
	vector <vector<int>> lineCost(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j){
			if (extraSpaces[i][j] < 0) {
				lineCost[i][j] = INT_MAX;
			}
			else if (j == n - 1) {
				lineCost[i][j] = 0;
			}
			else {
				lineCost[i][j] = extraSpaces[i][j] * extraSpaces[i][j];
			}
		}
	}
	vector<int> dp(n, INT_MAX);
	vector<int> breaks(n, -1);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i; j < n; ++j) {
			if (lineCost[i][j] == INT_MAX) continue;
			int cost = lineCost[i][j] + (j + 1 < n ? dp[j + 1] : 0);
			if (cost < dp[i]) {
				dp[i] = cost;
				breaks[i] = j + 1;
			}
		}
	}
	int i = 0;
	int lineNumber = 1;
	while (i < n) {
		cout << "Line " << lineNumber++ << ": ";
		for (int j = i; j < breaks[i]; ++j) {
			if (j > i) cout << " ";
			cout << words[j];
		}
		cout << endl;
		i = breaks[i];
	}

}


int main()
{

	string text;
	getline(cin, text);
	int lw;
	cin >> lw;

	string word;
	vector<string> words;
	istringstream stream(text);
	while (stream >> word) {
		words.push_back(word);
	}
	textWrap(words, lw);

	return 0;
}


