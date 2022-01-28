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
        int X,Y,Z;
        cin >> X >> Y >> Z;
        cout << X*(Z-Y);
    }
    return 0;
}