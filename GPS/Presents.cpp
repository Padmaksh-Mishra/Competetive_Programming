//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int hash[n];
    for(int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        hash[tmp - 1] = i;
    }
    for(int i = 0; i < n; i++) cout << hash[i] + 1 << " ";
    cout << endl;
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
