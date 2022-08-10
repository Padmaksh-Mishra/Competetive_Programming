// <--> Nefarious <--> ***

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;


void solve(){
    int x,y,n,r; cin >> x >> y >> n >> r;
    int maxBuy = r/x;
    if(maxBuy<n){
        cout << -1 << endl;
        return;
    }
    int p = (r-(n*x))/(y-x);
    if(p>n) p = n;
    cout << n-p << " " << p << endl;
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
