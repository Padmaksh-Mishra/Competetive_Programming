//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    string N; cin >> N;
    ll sum = 0;
    for(int i=0; i<N.length(); i++){
        sum = sum + ((int)N[i] - 48);
    }
    ll index = N.length();
    int missingNo = (9 - (sum % 9))%9;
    for(int i=0; i<N.length(); i++){
        if(missingNo < (((int)N[i])-48)){
            index = i;
            if(missingNo == 0) index = 1;
            break;
        }
    }
    for(int i=0; i<N.length(); i++){
        if(i == index) {
            cout << missingNo;
            index = -1;
            i--;
            continue;
        }
        cout << N[i];
    }
    if(index == N.length()) cout << missingNo;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    ll p = 0;
    while(TC--){
        p++;
        cout << "Case #" << p << ": " ;
        solve();
        cout << endl;
    }
    return 0;
}
