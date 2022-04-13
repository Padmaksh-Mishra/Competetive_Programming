//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    map<string,string> words;
    for(int i = 0; i < m;i++){
        string temp1,temp2; cin >> temp1 >> temp2;
        if(temp1.length() <= temp2.length()) temp2 = temp1;
        words[temp1] = temp2;
        //cout << temp1 << " " << temp2 << endl;
    }
    for(int i = 0; i <n; i++){
        string tmp;cin >> tmp;
        cout << words[tmp] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        solve();
    return 0;
}
