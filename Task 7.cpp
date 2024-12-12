#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // direction in this order (up, down, left, right)

vector<pair<int, int>> bfs(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
	int rows = maze.size();
	int cols = maze[0].size();

	queue<pair<pair<int, int>, vector<pair<int, int>>>> q;
	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
	visited[start.first][start.second] = true;
	q.push({ start, {start} });

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		pair<int, int> current = front.first;
		vector<pair<int, int>> path = front.second;

		if (current == end) {
			return path;
		}

		for (auto dir : directions) {
			int newrow = current.first + dir[0];
			int newcol = current.second + dir[1];

			if (newrow >= 0 && newrow < rows && newcol >= 0 && newcol < cols && maze[newrow][newcol] != 1 && !visited[newrow][newcol]) {
				visited[newrow][newcol] = true;
				vector<pair<int, int>> new_path = path;
				new_path.push_back({ newrow, newcol });
				q.push({ {newrow, newcol}, new_path });
			}
		}

	}
	return {};
}

void printMazeWithPath(vector<vector<int>>& maze, const vector<pair<int, int>>& path) {
	vector<vector<char>> displayMaze(maze.size(), vector<char>(maze[0].size()));
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[0].size(); j++) {
			if (maze[i][j] == 1)
				displayMaze[i][j] = '#'; // Walls
			else
				displayMaze[i][j] = ' '; // Empty spaces
		}
	}

	for (auto p : path) {
		displayMaze[p.first][p.second] = '*';
	}
	for (int i = 0; i < maze.size(); i++) {
		for (int j = 0; j < maze[0].size(); j++) {
			cout << displayMaze[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	vector<vector<int>> maze = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
		{1,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
		{1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
		{1,0,1,0,1,1,1,0,1,1,1,0,1,0,1},
		{1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
		{1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,0,0,0,1,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}

	};

	pair<int, int> start = { 12, 0 }; // start
	pair<int, int> end = { 1, 14 }; // end

	vector<pair<int, int>> path = bfs(maze, start, end);

	if (!path.empty()) {
		printMazeWithPath(maze, path);
		cout << "Path to the exit: " << endl;
		for (auto p : path) {
			cout << "(" << p.first << ", " << p.second << ") ";
		}
		cout << endl;
	}
	else {
		cout << "No path found." << endl;
	}

}