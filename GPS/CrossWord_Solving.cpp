//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    string s,t; cin >> s >> t;
    int mini = 10001;
    int finally[1001];
    vector<int> changes;
    for(int i = 0; i < m-n+1; i++){
        int count = 0;
        for(int j = 0 ;j<n ;j++){
            if(s[j] != t[i+j]){
                count++;
                changes.push_back(j+1);
            } 
        }
        if(mini >= count){
            mini = min(mini, count);
            for(int k = 0 ;k<mini ;k++){
                finally[k] = changes[k]; 
            }
        }
        changes.clear();	
    }
    cout << mini << endl;
    for(int k = 0 ;k<mini ;k++){
        cout << finally[k] << " "; 
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);  

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
