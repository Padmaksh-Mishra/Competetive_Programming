//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
# define ll long long

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC; 
    while(TC--){
        ll N;
        ll temp;
        cin >> N;
        for(int i = 1 ; i <= N; i++){
            cout << (i^(i-1)) << " ";
        }
        cout << endl;
    }
    return 0;
}