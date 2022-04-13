//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,l; cin >> n >> l;
    int laltenes[n];
    for(int i = 0; i < n; i++) cin >> laltenes[i];
    sort(laltenes, laltenes + n);
    int startdiff = 2*laltenes[0];
    int enddiff = 2*(l-laltenes[n-1]);
    int diffarry[n-1];
    int maxdiff = max(startdiff, enddiff);
    for(int i = 1;i<n;i++){
        int ans = laltenes[i] - laltenes[i-1];
        maxdiff = max(maxdiff, ans);
    }
    cout << fixed << setprecision(9) << (maxdiff/2.0) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
    
    return 0;
}
