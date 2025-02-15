

// problem number 4

// Problem Statement

// Rezia is trapped in a 2D maze of  size, starting at position R, and her goal is to reach the exit marked by D. The maze contains blocks represented by #, and she can only traverse through cells marked with dots (.). As she need to escape as early as possible, we need to determine the path she will follow.

// Place an X in each cell representing Rezia's route to exit the maze. If there is no viable path for her to exit, leave the maze unchanged.

// Note: Rezia can move in four directions – right, left, up, and down. It is crucial to adhere to the specified order: attempting right first, then left, followed by up, and finally down.

// Input Format

// First line will contain  and .
// Next you will be given the 2D matrix.
// Constraints

// Output Format

// Output the final maze with marked X indicating the path she will follow.



#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005]; 
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; 

bool valid(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj]=0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++) {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;

            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#') {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj]=level[par_i][par_j] + 1;
                parent[ci][cj] = {par_i, par_j};
            }
        }
    }
}



int main() {   
    memset(vis, false, sizeof(vis));   
    memset(level,-1,sizeof(level));
    memset(parent, -1, sizeof(parent));  
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int si, sj, di, dj;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'D') {
                di = i;
                dj = j;
            }
        }
    }
    
    bfs(si, sj);
    
    if (0 < level[di][dj])
    {
        int a = di;
        int b = dj;
        while(true)
        {
            pair<int, int> par = parent[a][b];
            a = par.first;
            b = par.second;
            if (grid[a][b] == 'R')
            {
                break;
            }
            grid[a][b] = 'X';
        }
    }  


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
