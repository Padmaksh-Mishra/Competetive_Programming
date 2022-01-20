//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        ll K, N = 0;
        cin >> K;
        while(K%2==0){
            N++;
            K /= 2;
        }
        cout << N << "\n";
    }
    return 0;
}