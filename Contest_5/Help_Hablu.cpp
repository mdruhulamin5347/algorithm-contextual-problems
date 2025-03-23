#include <bits/stdc++.h>
using namespace std;

long long cntsub(string& s, string& t) {
    int n = s.length();
    int m = t.length();
    
    vector<vector<long long>> dp(n + 5, vector<long long>(m + 5, 0));
    
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][m];
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string t;
        cin >>t;
        
        long long result = cntsub(s, t);
        cout << result << endl;
    }
    
    return 0;
}