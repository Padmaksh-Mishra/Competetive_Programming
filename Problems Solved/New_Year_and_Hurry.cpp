//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int arr[11];
    int n,k; cin >> n >> k;
    for(int i=0; i<n+1; i++){
        arr[i] = (i*(i+1))/2;
        //cout << arr[i] << " ";
    }
    //cout << endl;
    double ans = (240.0-k)/5.0;
    //cout << ans << endl;
    cout << (upper_bound(arr,arr+n+1,ans)) - arr - 1  << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
