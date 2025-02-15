

// problem number 3

// Problem Statement

// You will be given a chessboard of  size. You can move anywhere in the chessboard freely. You will be given two cells - the knight's cell  ( and ), and the queen's cell  ( and ). You need to tell the minimum number of steps for the knight to attack the queen if the queen doesn't move.

// A knight move in 8 directions. The directions are given below:image

// Input Format

// First line will contain , the number of test cases.
// First line of each test case will contain  and .
// Second line of each test case will contain  and .
// Third line of each test case will contain  and .
// Constraints

// Output Format

// Output the minimum number of steps for the knight to reach the queen. If you can't reach to queen, print .


#include <bits/stdc++.h>
using namespace std;

int n,m;
int grid[105][105];
bool vis[105][105];
int level[105][105];
vector<pair<int,int>> d = {{-2,-1},{-2,1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2}};
bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

void bfs(int si,int sj){
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;
    level[si][sj]=0;
    while(!q.empty()){
        pair<int,int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0; i<8; i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 0){
                q.push({ci,cj});
                vis[ci][cj]=true;
                level[ci][cj]=level[par_i][par_j] + 1;
            }
        }
    }
    
}

int main(){       
    int t;
    cin >> t;
    while(t--){
        memset(grid,0,sizeof(grid));
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        cin >> n >> m;
        grid[n][m];
        int si,sj,di,dj;
        cin >> si >> sj >> di >> dj;
        bfs(si,sj);
        
        cout << level[di][dj] << endl;
    }
    return 0;
}