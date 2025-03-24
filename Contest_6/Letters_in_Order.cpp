
#include <bits/stdc++.h>
using namespace std;

int main(){
    set<char>char_set;
    string s;
    cin >> s;
    for(char ch : s){
        char_set.insert(ch);
    }
    for(char ans : char_set){
        cout << ans;
    } 
    return 0;
}