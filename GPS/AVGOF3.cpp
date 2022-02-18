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
        int X;
        cin >> X;
        //cout << X << endl;
        // if(floor(X) != X){
        //     X = int(X) + 1;
        // }
        
        cout << X-1 <<" "<< X <<" "<< X+1 << endl;
    }
    return 0;
}