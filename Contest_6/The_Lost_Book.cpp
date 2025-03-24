#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int code;
        cin >> code;
        v.push_back(code);
    }
    int q;
    cin >> q;

    for(int i=0; i<n; i++){
        if(v[i] == q){
            cout << i;
            return 0;
        }
        
    }
    cout << -1;  

    return 0;
}