//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;
int noOf1(int n){
    int count = 0;
    while(n){
        if(n&1) count++;
        n=(n>>1);
    }
    return count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int a; cin >> a;
        string s; cin >> s;
        int n = stoi(s,0,2);
        ll ans = (n) ? 1 : 0;
        n--;
        while(n--){
            ans = (ans<<1)  + 1;
        }
        cout << ans << endl;

    }
    return 0;
}
