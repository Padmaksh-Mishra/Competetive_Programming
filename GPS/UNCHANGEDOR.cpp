//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int N; cin >> N;
    cout << N - (int)log2(N) -1 << endl;
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
