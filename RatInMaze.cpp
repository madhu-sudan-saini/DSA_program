#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:

void solve(vector<vector<int>>& maze,
           int row,
           int col,
           string path,
           vector<string>& ans,
           vector<vector<int>>& visited) {

    int n = maze.size();

    
    if (row < 0 || row >= n || col < 0 || col >= n) {
        return;
    }

    
    if (maze[row][col] == 0 || visited[row][col] == 1) {
        return;
    }


    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[row][col] = 1;

    solve(maze, row + 1, col, path + 'D', ans, visited);

    solve(maze, row, col - 1, path + 'L', ans, visited);

    solve(maze, row, col + 1, path + 'R', ans, visited);


    solve(maze, row - 1, col, path + 'U', ans, visited);

    visited[row][col] = 0;
}

vector<string> ratInMaze(vector<vector<int>>& maze) {

    int n = maze.size();

    vector<string> ans;

    // Source or destination is blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        return ans;
    }

    vector<vector<int>> visited(n, vector<int>(n, 0));

    solve(maze, 0, 0, "", ans, visited);

    return ans;
}

};

int main() {

vector<vector<int>> maze = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};

Solution obj;

vector<string> ans = obj.ratInMaze(maze);

for (string path : ans) {
    cout << path << endl;
}

return 0;

}
