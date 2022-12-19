//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    arr[0] = 0;
    for(int i = 1; i < n+1;i++) cin >> arr[i];
    int k = 1;
    //int difs[n-1];
    //for(int i = 0; i < n-1; i++) difs[i] = arr[i+1] - arr[i];
    vector<int> ans;
    while(k<=n){
        bool accept = true;
        for(int i = 0; i+k < n; i++){
            if(arr[i+1] - arr[i] != arr[i+k+1] - arr[i+k]){
                accept = false;
                break;
            }
        }
        if(accept) ans.push_back(k);
        k++;
    }
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end();it++) cout << *it << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
