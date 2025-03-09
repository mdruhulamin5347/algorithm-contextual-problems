
// problem number 2

// The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four previous terms instead of two.

// The Tetranacci sequence Tn is defined as follows:

// T0 = 0, T1 = 1, T2 = 1,T3 = 2
// For  , Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
// Given an integer 𝑛, return the value of Tn

// Note : You must solve this problem using Recursion. (Top Down)

// Input Format

// A single integer n representing the position in the Tetranacci sequence.

// Constraints

// The result is guaranteed to fit within a 32-bit integer (  231-1 )
// Output Format

// Print a single integer, the value of Tn



#include <bits/stdc++.h>
using namespace std;
int dp[35];

long long tetra(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = tetra(n-1) + tetra(n-2) + tetra(n-3) + tetra(n-4);
    return dp[n];
} 

int main(){
    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << tetra(n);
    return 0;
}