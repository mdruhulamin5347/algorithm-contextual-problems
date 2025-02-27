

// problem number 1

// Problem Statement

// You will be given  numbers of nodes,  numbers of edges in a graph. For each edge you will be given ,  and  which means there is a connection from  to  only and for which you need to give  cost. The value of nodes could be from  to .

// You will be given a source node . Then you will be given a test case , for each test case you will be given a destination node . You need to tell the minimum cost from source node to destination. If there is no possible path from  to  then print Not Possible.

// Note: If there is a negative weight cycle in the graph, then no answer would be correct. So print one line only - "Negative Cycle Detected".

// Input Format

// First line will contain  and .
// Next  lines will contain ,  and .
// Next line will contain source node .
// Next line will contain , the number of test cases.
// For each test case, you will get .
// Constraints

// Output Format

// Output the minimum cost for each test case.


#include <bits/stdc++.h>
using namespace std;


class Edge{
    public:
    int a,b,c;
    Edge(int a,int b,int c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main(){    
    int n,e;
    cin >> n >> e;
    vector<Edge>edge_list;
    vector<long long>dis(n+5,LLONG_MAX);
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b,c));
    }

    int src;
    cin >> src;    
    dis[src]=0;
    for(int i=0; i<n-1; i++){
        for(auto ad : edge_list){
            int a,b,c;
            a = ad.a;
            b = ad.b;
            c = ad.c;
            if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a] + c;
            }
        }
    }



    for(auto ad : edge_list){
        int a,b,c;
        a = ad.a;
        b = ad.b;
        c = ad.c;
        if(dis[a] != LLONG_MAX && dis[a] + c < dis[b]){
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(dis[x] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[x] << endl;
    }

    return 0;
}