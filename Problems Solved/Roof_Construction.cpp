
# include <bits/stdc++.h>	
# define endl "\n"
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        ll n;
        cin >> n;
        ll d = log2(n-1);
        d = pow(2,d);
        for(ll i = d-1; i > 0; i--){
            cout << i << " ";
        }
        cout << 0 << " ";
        for(ll i = d; i < n; i++){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}