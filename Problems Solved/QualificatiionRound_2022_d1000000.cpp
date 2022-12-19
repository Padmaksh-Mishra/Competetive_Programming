//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int N; cin >> N;
    int dice[N];
    int length = 0;
    for(ll i = 0; i < N; i++) cin >> dice[i];
    sort(dice, dice + N);
    int comprator = 0;
    for(int i = 0; i < N;i++){
        if(dice[i] > comprator) length++;
        else comprator--;
        comprator++;
    }
    cout << length << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll TC = 1;
    cin >> TC;
    ll x = 0;
    while(TC--){
        x++;
        cout << "Case #" << x << ": ";
        solve();
    }
    return 0;
}
