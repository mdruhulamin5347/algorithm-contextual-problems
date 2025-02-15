

// problem number 1

// Problem Statement

// You will be given a 2D matrix of size  which will contain only dot() and minus() where dot() means you can go in that cell and minus() means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// You will be given the indexes of two cells - (,) and (,). You need to tell if these  and  cells are in the same component or not. Same component means you can go from  to .

// Input Format

// First line will contain  and .
// Next you will be given the 2D matrix.
// Next line will contain  and .
// Last line will contain  and .
// Constraints

// Output Format

// Output "YES" if those cell are in the same component, "NO" otherwise.


#include <bits/stdc++.h>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

void dfs(int si,int sj){
    vis[si][sj]=true;

    for(int i=0; i<4; i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj]=='.'){
            dfs(ci,cj);
        }
    }

}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    memset(vis,false,sizeof(vis));
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    dfs(si,sj);

    if(vis[di][dj])
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;


    return 0;
}