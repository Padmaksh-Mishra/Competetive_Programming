//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        string s;
        cin >> s;
        int x = 0;
        for(auto i : s){
            x = x ^ i;
        }
        if(x==0){
            cout << "-1" << endl;
        }else{
            cout << (char)x << endl;
        }
    }
    return 0;
}