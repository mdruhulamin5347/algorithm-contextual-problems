

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    vector<int>sequence;
    int start = 1;
    for(int i=0; i<n; i+=3){
        sequence.push_back(start);
        sequence.push_back(start);
        sequence.push_back(start);
        start++;
    }

    vector<long long> pre_sum(n + 1, 0);
    for(int i=1; i<=n; i++){
        pre_sum[i] = pre_sum[i-1] + sequence[i-1];
    }

    while(q--){       
        int l,r;
        cin >> l >> r;

        long long distance = pre_sum[r] - pre_sum[l-1];
        cout << distance << endl;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> sequence;
    int start = 1;

    while(sequence.size() < n) {
        sequence.push_back(start);
        sequence.push_back(start);
        sequence.push_back(start);
        start++;
    }

    vector<long long> pre_sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pre_sum[i] = pre_sum[i - 1] + sequence[i - 1];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << pre_sum[r] - pre_sum[l - 1] << endl;
    }
    return 0;
}