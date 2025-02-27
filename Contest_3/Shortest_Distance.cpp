

// problem number 2

// You'll be given a graph of  nodes and  edges. For each edge, you'll be given ,  and  which means there is an edge from  to  only and which will cost .

// Also, you'll be given  queries, for each query you'll be given  and , where  is the source and  is the destination. You need to print the minimum cost from  to  for each query. If there is no connection between  and , print .

// Note: There can be multiple edges from one node to another. Make sure you handle this one.

// Input Format

// First line will contain  and .
// Next  lines will contain ,  and .
// After that you'll get .
// Next  queries will contain  and .
// Constraints

// Output Format

// Output the minimum cost for each query.



#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cin >> n >> e;
    long long int dis[n+5][n+5];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                dis[i][j]=0;
            else 
                dis[i][j]=LLONG_MAX;
        }
    }

    while(e--){
        long long a,b,c;
        cin >> a >> b >> c;
        dis[a][b]=min(dis[a][b],c);
    }

    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX && dis[i][k] + dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int x,y;
        cin >> x >> y;
        if(dis[x][y] == LLONG_MAX) cout << -1 << endl;
        else cout << dis[x][y] << endl;
    }
    return 0;
}