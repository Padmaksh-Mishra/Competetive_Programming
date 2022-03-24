//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int countTRUE(string str,ll length) {
    int count = 0;

    for(int i = 0; i < length; i++) {
        if(str[i] == '1') count++;
    }
    return count;
}
void solve(){
    int N; cin >> N;
    string str; cin >> str;
    int ones = countTRUE(str,N);
    int temp = min(ones,N-ones);
    if(temp == (N>>1)) cout << N << endl;
    else if(temp == 1) cout << 3 << endl;
    else cout << temp + temp + 1 << endl;
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
