

// problem number 2


// The Tetranacci sequence is an extension of the well-known Fibonacci sequence, incorporating four previous terms instead of two.

// The Tetranacci sequence Tn is defined as follows:

// T0 = 0, T1 = 1, T2 = 1,T3 = 2
// For  , Tn = Tn-1 + Tn-2 + Tn-3 + Tn-4
// Given an integer 𝑛, return the value of Tn

// Note : You must solve this problem using Loop. (Bottom up)

// Input Format

// A single integer n representing the position in the Tetranacci sequence.

// Constraints

// The result is guaranteed to fit within a 64-bit integer (  263-1 )
// Output Format

// Print a single integer, the value of Tn


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long tetra[n+5];
    memset(tetra,0,sizeof(tetra));
    tetra[0]=0;
    tetra[1]=1;
    tetra[2]=1;
    tetra[3]=2;

    for(int i=4;i<=n; i++){
        tetra[i]=tetra[i-1] + tetra[i-2] + tetra[i-3] + tetra[i-4];
    }

    cout << tetra[n]<< endl;
    return 0;
}