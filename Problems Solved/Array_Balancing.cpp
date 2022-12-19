//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int a[n],b[n];
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    ll ans = 0;
    for(int i=1; i<n; i++){
        ll tmpO = abs(a[i]-a[i-1]) + abs(b[i]-b[i-1]);
        ll tmpN = abs(a[i]-b[i-1]) + abs(b[i]-a[i-1]);
        if(tmpO>tmpN){
            swap(a[i-1],b[i-1]);
            ans += tmpN;
        }else ans += tmpO;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
