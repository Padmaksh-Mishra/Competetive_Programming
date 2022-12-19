//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    string str; cin >> str;
    vector<char> vch;
    for(int i=0; i<str.size(); i++){
        bool duble = false;
        if(str[i]<=str[i+1]){
            for(int j=i+1; j<str.size(); j++){
                if(str[i]<str[j]) {
                    duble=true;
                    break;
                }else if(str[i]>str[j]) break;   // Waraning iss line ki **** iske na hone ki waja se ans galat ho raha tha
            }
        }
        if(duble) vch.push_back(str[i]);
        vch.push_back(str[i]);
    }
    for(auto i=vch.begin(); i!=vch.end(); i++) cout << *i;
    //cout << str[str.size()-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    int cases = 0;
    while(TC--){
        cases++;
        cout << "Case #" << cases << ": ";
        solve();
        cout << endl;
    }
    return 0;
}
