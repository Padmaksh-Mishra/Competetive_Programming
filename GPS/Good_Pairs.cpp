//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    int minI,maxI,min = 1e9 + 1,max = -1;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        if(arr[i] < min){
            min = arr[i];
            minI = i;
        }
        if(arr[i] > max){
            max = arr[i];
            maxI = i;
        }
    }
    cout << maxI +1 << " " << minI + 1 << endl;
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
