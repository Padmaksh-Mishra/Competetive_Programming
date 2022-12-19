//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    int arr[n];
    set<int> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    int old = s.size();
    for(int i=0;i<n;i++){
        int sub = arr[i] - k;
        s.insert(sub);
    }
    if(s.size() == (2*old)) cout << "NO" << endl;
    else cout << "YES" << endl;
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
