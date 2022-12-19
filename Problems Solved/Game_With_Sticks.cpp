//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    int POI = m*n;
    int gold = 1;
    while(POI>0){
        POI = POI - (m+n-1);
        if(POI>0) gold ^=1;
        m--;
        n--;
    }
    if(gold) cout << "Akshat" << endl;
    else cout << "Malvika" << endl;
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
