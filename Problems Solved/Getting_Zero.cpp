//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int pow2(int n){
    int count =0;
    while(true){
        if(n&1) break;
        else count++;
        n>>=1;
    }
    return count;
}
void solve(){
    int n; cin >> n;
    int array[n];
    vector<int> answer;
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        if(array[i]==0){
            answer.push_back(0);
            continue;
        }
        int ops = 16;
        for(int j = 0; j < 16; j++){
            int twosIhave = pow2(array[i]+j);
            //deb(twosIhave);
            ops = min(ops,j+15-twosIhave);
            //cout << ops << endl;
        }
        answer.push_back(ops);
    }
    for(auto it = answer.begin(); it != answer.end(); it++) cout << *it << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything
    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
