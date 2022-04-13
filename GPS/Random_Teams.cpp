//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    ll n,m; cin >> n >> m ;
    ll r = n%m;
    ll q = n/m;
    ll kmin = (r*(q+1)*q/2) + ((m-r)*(q-1)*q/2);
    ll kmax = (n-m+1)*(n-m)/2;
    cout << kmin << " " << kmax << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();    
    return 0;
}
