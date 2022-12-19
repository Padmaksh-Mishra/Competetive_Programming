//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        string s; cin >> s;
        char c; cin >> c;
        bool won = false;
        for(int i = 0; s[i] != '\0';i++) {
            if((s[i] == c)&&!(i&1)) {
                cout << "Yes" << endl;
                won = true;
                break;
            }
        }
        if(!won) cout << "No" << endl;

    }
    return 0;
}
