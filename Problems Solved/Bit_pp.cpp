//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    string tmp;
    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(tmp[1] == '+') x++;
        else x--;
    }
    cout << x << endl;
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
