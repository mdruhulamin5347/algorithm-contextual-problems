

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    int fruits[n+5];
    for(int i=1; i<=n; i++){
        cin >> fruits[i];
    }
    long long pre_sum[n+5];
    pre_sum[0] = 0;
    pre_sum[1] = fruits[1];
    for(int i=2; i<=n; i++){
        pre_sum[i] = pre_sum[i-1] + fruits[i];
    }

    while(q--){
        int l,r;
        long long sum = 0;
        cin >> l >> r;
        sum = abs(pre_sum[r] - pre_sum[l-1]);
        cout << sum << endl;
    }

    return 0;
}