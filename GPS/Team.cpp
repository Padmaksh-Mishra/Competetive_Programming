//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int probs = 0;
    for(int i = 0; i < n; i++){
        int ones = 0;
        for(int h = 0; h <3;h++){
            int tmp;cin >> tmp;
            if(tmp) ones++;
        }
        if(ones>1) probs++;
    }
    cout << probs << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
    return 0;
}
