

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        long long curr_sum = 0;
        for(int i=0; i<n-2; i++){
            cin >> arr[i];
            curr_sum += arr[i];
        }
        long long total_sum;
        cin >> total_sum;
        long long missing_val = total_sum - curr_sum;
        cout << missing_val + 1 << endl;
        
    }
    return 0;
}