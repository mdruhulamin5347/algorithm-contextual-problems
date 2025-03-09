

// problm number 5

// Problem Statement

// Pile of Word is a word formed by rearranging the letters of another word, using all the original letters exactly once. In other words, it involves creating a new word by rearranging the characters of a given word. It is possible that after rearranging it looks like the original one.

// You will be given two strings  and . You need to determine if the strings are Pile of Word of each other.

// Input Format

// First line will contain , the number of test cases.
// Each line of the test case will contain  and  separated by a space. The string will contain Enlish small alphabets only.
// Constraints

// . Here || means the length of string.
// Output Format

// Ouptut  if the strings are Pile of Word to each other,  otherwise.


#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1,s2;
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            cout << "NO" << endl;    
            continue;                
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1 == s2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}