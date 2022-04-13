//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int setBits(int n){
    int count = 0;
    while(n){
        if(n&1) count++;
        n >>= 1;
    }
    return count;
}

void solve(){
    int n,m,k; cin >> n >> m >> k;
    int army[m+1];
    for(int i=0;i<m+1;i++) cin >> army[i];
    int friends = 0;
    for(int i=0;i<m;i++){
        int tmp = setBits(army[i]^army[m]);
        if(tmp<=k) friends++;
    }
    cout<<friends<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
    return 0;
}
