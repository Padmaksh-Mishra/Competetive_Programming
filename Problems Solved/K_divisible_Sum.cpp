//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    int factor = (n%k) ? (n/k)+1 : (n/k);
    k = k*factor;
    int ans = (k%n) ? (k/n) + 1: (k/n);
    cout << ans << endl;
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
