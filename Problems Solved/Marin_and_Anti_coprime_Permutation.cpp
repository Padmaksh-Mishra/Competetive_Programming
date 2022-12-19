//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 998244353;
using namespace std;
ll facts[501];
void initialize(){
    facts[0] = 1;
    for (int i=1; i<501 ; i++){
        facts[i] = (facts[i-1] * i)%MOD;
    }
}
void solve(){
    int n; cin >> n;
    if(n&1) cout << 0 << endl;
    else {
        ll ans  = (facts[(n>>1)]*facts[(n>>1)])%MOD;
        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    initialize();
    int TC;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
