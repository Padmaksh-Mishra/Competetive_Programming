//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    double n,k; cin >> n >> k;
    double num = k+0.0001;
    num = num - 0.0001;
    for(int i = 2; num<n ; i++){
        num = num/(i-1);
        num = num*i;
    }
    double ans = num/n;
    //cout << ans << endl;
    cout << ((ans == (int)ans) ? ans : (int)ans + 1) << endl;
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
