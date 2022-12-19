//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int t1 = (n%k) ? (n/k)+1 : (n/k);
    int t2 = (m%k) ? (m/k)+1 : (m/k);
    cout << t1+t2 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
