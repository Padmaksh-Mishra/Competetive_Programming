//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];
    if(n==1){
        if(arr[0]>1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }else{
    sort(arr,arr+n);
    if(arr[n-1]-arr[n-2] <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
