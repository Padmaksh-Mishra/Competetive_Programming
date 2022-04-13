//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    string binStr; cin >> binStr;
    ll extras = 0;
    for (int i = 0; i < n-1; i++){
        if(binStr[i]=='0'){
            if(binStr[i+1]=='1'){
                if(i<n-2)
                if(binStr[i+2]=='0') extras++;
            }
            else if(binStr[i+1]=='0') extras+=2;
        }
    }
    cout<<extras<< endl;
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
