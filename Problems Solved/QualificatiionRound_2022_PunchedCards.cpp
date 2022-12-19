//Coding_Duck PM REDACTED

# include <iostream>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    ll R,C; cin >> R >> C;
    R = ((R<<1) ^ 1);
    C = ((C<<1) ^ 1);
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if((r==0)&&(c==0)) cout << ".";
            else if((r==0)&&(c==1)) cout << ".";
            else if((r==1)&&(c==0)) cout << ".";
            else if((r==1)&&(c==1)) cout << ".";
            else if(r&1){
                if(c&1) cout << ".";
                else cout << "|";
            }else {
                if(c&1) cout << "-";
                else cout << "+";
            }
        }
        cout << endl;
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll TC = 1;
    cin >> TC;
    ll x = 0;
    while(TC--){
        x++;
        cout << "CASE #" << x << ": " << endl;
        solve();
    }
    return 0;
}
