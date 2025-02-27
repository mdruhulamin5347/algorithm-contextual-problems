
// problem number 4

// Problem Statement

// You are given an array  representing the heights of  vertical lines positioned at equally spaced intervals along a two-dimensional plane. The -th line's height is represented by the integer  where  and the height will be unique.

// You need to find the two lines, such that together with the x-axis forms a container that can hold the most water in term of height.

// Note: Print the left index first, then the right index.

// Input Format

// First line will contain , the number of test cases.
// First line of each test case will contain .
// Second line of each test case will contain the array .
// Constraints

// Output Format

// Ouptut two integers, the index of those two lines that can contain the most water in term of height.


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int>height;
        priority_queue<int>pq;
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int h;
            cin >> h;
            height.push_back(h);
            pq.push(h);
        }
        vector<int>v;  
        for(int i=0; i<2; i++){                                 
            for(int j=0; j<n; j++){
                if(height[j] == pq.top()){
                    v.push_back(j);
                }
            }
            pq.pop();
            
            
        }  
        sort(v.begin(),v.end());
        cout << v[0] <<" " << v[1] << endl; 
    }
    return 0;
}