//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    ll sum;
    int i;
    if((n%3==0)||(n%3==2)){
        sum = 2;
        i = 1;
    }
    else{
        sum = 1;
        i = 2;
    }
    cout << sum;
    while(n>sum){
        cout << i;
        sum += i;
        if(i&1) i = 2;
        else i = 1; 
        }
    
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC; cin >> TC;
    while(TC--){
        solve();
        cout << endl;
    }
    return 0;
}
