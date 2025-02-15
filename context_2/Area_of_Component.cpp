
// problem number 2

// Problem Statement

// You will be given a 2D matrix of size  which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(-) means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

// Note: If there are no components, print -1.

// Input Format

// First line will contain  and .
// Next you will be given the 2D matrix.
// Constraints

// Output Format

// Output the minimum area.


#include <bits/stdc++.h>
using namespace std;
int n,m,cnt;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

void dfs(int si,int sj){
    cnt++;
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
    
    int mnArea = INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j]=='.'){
                cnt = 0;        
                dfs(i,j);
                mnArea = min(mnArea,cnt);                
            }            
        }   
    }

    if(mnArea==INT_MAX)
        cout << -1 << endl;
    else
        cout << mnArea << endl;
    
    return 0;
}