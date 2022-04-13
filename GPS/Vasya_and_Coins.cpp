//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int a,b; cin >> a >> b;
    if(a == 0) cout << 1 << endl;
    else {
        cout << a+(b<<1)+1 << endl;
    }
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
