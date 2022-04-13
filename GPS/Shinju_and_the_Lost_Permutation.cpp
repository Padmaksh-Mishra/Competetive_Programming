//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int c[n];
    bool sahiHAi = false;
    bool baap = false;
    bool kill = false;
    int index_1 = -1;
    for(int i = 0; i < n;i++){
        cin >> c[i];
        if(baap){
            kill = true;
            if(c[i]==1) {
                kill = false;
            }
            baap = false;
        }
        if(index_1 != -1) {
            if(c[i]-c[i-1]!=1) {
                sahiHAi = false;
                
            }
        } 
        if((c[i] == 1)&&(!sahiHAi)) {
            index_1 = i;
            sahiHAi = true;
        }
        if(c[i] == n) baap = true;
    }
    if((sahiHAi)&&(!kill)) cout<<"YES" << endl;
    else cout<<"NO" << endl;
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
