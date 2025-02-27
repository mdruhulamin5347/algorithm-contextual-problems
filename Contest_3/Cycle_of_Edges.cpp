

// problem number 3

// Problem Statement

// You will be given an undirected graph where there will be  nodes and  edges. You need to tell the number of edges that can create a cycle in the graph.

// Note: Duplicate edges as input can not be possible. The value of nodes are from  to .

// Input Format

// First line will contain  and .
// Next  lines will contain  and  which means there is a edge between  and .
// Constraints

// Output Format

// Output the number of edges that can create a cycle.


#include <bits/stdc++.h>
using namespace std;

vector<int>par(100005,-1);
vector<int>group_size(100005,1);

int find(int node){
    if(par[node] == -1) return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1,int node2){
    int leader1 = find(node1);
    int leader2 = find(node2);
    if(group_size[leader1] >= group_size[leader2]){
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }        
    else {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }

}

int main(){
    int n,e;
    cin >> n >> e;

    int cnt = 0;
    while(e--){
        int a,b;
        cin >> a >> b;
        if(find(a) == find(b)){
            cnt++;
        }
        else{
            dsu_union(a,b);
        }
    }

    cout << cnt << endl;
    
    return 0;
}