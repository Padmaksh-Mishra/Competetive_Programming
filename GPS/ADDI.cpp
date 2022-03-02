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
        
        ll n,count = 0;
        cin >> n;
        while(n){
            int bit = (n&1);
            if(bit == 0){
                count++;
            }
            n = (n>>1);
        }
        cout << count << endl;
    }
    return 0;
}