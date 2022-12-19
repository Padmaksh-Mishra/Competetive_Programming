//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    ll n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);
    ll max_occurances = 1;
    ll ultimately = 1;
    for(int i = 1; i < n; i++){
        if(arr[i]==arr[i-1]){
            max_occurances++;
        }else max_occurances = 1;
        ultimately = max(ultimately,max_occurances);
    }
    ll extra = 0,present = ultimately,more = n-ultimately,ans = 0;
    while(more>0){
        ans++;
        extra = present;
        ans += min(more,extra);
        more -=extra;
        present = present + extra;
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
