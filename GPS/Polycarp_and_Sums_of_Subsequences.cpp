//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int b[7];
    for(int i = 0; i < 7;i++) cin >> b[i];
    int a1 = b[0];
    int a2 = b[1];
    int allSum = b[6];
    int a3 = allSum - a1 - a2;
    cout << a1 << " " << a2 << " " << a3 << endl;
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
