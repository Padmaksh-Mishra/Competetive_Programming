//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    ll x,y,z; cin >> x >> y >> z ;
    //cout << x%z << " " << y%z << endl;
    ll debt = min(z-(x%z),z-(y%z));
    if(debt==z) debt = 0;
    if((x%z) + (y%z) < z) debt = 0;
    cout << (x+y)/z << " " << debt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


        solve();
    
    return 0;
}
