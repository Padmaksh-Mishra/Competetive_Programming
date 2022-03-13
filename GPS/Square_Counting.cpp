//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        ll n,s; cin >> n >> s;
        cout << s/(n*n) << endl;
    }
    return 0;
}
