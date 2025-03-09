
// problem number 3
// Problem Statement
// You will be given a positive integer . You will start from  and do some steps (possibly zero).
// In each step you can choose one of the following:
// Add  with the current value
// Multiply by  with the current value
// Can you tell if you can reach  by using any number of steps you want.
// Input Format
// First line will contain , the number of test cases.
// In each test case you will be given .
// Constraints
// Output Format
// Print "YES" if you can reach , "NO" otherwise.



#include <bits/stdc++.h>
using namespace std;

int dp[1000005];

bool reach(int reach_val, int cur_val)
{
    if (dp[cur_val] != -1) return dp[cur_val];       

    if (cur_val > reach_val) {
        dp[cur_val] = false;
        return false;
    }

    if (cur_val == reach_val) {
        dp[cur_val] = true;
        return true;
    }

    dp[cur_val] = reach(reach_val, cur_val * 2) || reach(reach_val, cur_val + 3);
    return dp[cur_val];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;  
        memset(dp,-1,sizeof(dp));
        if(reach(n,1))   
            cout << "YES" << endl;  
        else   
            cout << "NO" << endl;
    }
    return 0;
}