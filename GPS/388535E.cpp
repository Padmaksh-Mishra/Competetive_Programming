//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    ll l ,r; cin >>l >> r;
    ll xord[r-l+1];
    ll max = -1;
    bool lost = false;
    for(ll i=0;i<(r-l+1);i++){
        cin >> xord[i];
        if(xord[i] > max) max = xord[i];
        if(xord[i] == 0){
            lost = true;
        }
    }
    if(lost) cout << 0 << endl;
    else {
        int ans = (max^r);
        cout << ans << endl;
    }
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
