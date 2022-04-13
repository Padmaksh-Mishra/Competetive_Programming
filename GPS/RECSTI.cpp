//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int N; cin >> N;
    int hash[100] = {0,};
    int stks[100];
    for(int i = 0; i < N; i++){
        cin >> stks[i];
        hash[stks[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < 100; i++){
        ans +=(hash[i]&1);
    }
    cout << ans + (4-(ans+N)%4)%4 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
