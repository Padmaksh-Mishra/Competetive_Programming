//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int X[n];
    for (int i = 0; i < n; i++) cin >> X[i];
    int Y[n];
    Y[0] = 0;
    cout << 0 << " ";
    for(int i = 1; i < n; i++){
        Y[i] = ((X[i-1]^Y[i-1])&(~X[i]));   // K-map ka kaam dek BSDK padhi kabi bekar nahi jaati
        cout << Y[i] << " ";
    }
    cout << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
