//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int min = 101,mini;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(min >= arr[i]) {
            mini = i;
            min = arr[i];
        }
        //deb(mini);
    }
    int maxi = max_element(arr,arr+n) - arr;
    // deb(maxi);
    // deb(mini);
    if(mini>maxi) cout << (n-1-mini) + maxi << endl;
    else cout << (n-1-mini) + maxi - 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
