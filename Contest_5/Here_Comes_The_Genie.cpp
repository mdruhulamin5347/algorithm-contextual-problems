#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int total_balls=0;
    cin >> n;
    vector<int>balls;
    for(int i=0; i<n; i++){
        int ball;
        cin >> ball;
        balls.push_back(ball);
    }
    sort(balls.begin(), balls.end(), greater<int>());

    for(int i=0,j=1; j<n; i++,j++){
        if(balls[i] == balls[j]){
            balls[j] = balls[j] - 1;
        }        
    }
    for(int val : balls){
        // cout << val << " ";
        total_balls += val;
    }
    cout << total_balls;
    return 0;
}