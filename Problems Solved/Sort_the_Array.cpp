//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n],sarr[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
        sarr[i] = arr[i];
    }
    sort(sarr,sarr+n);
    int i = -1,j = -1;
    for(int k = 0; k < n; k++){
        if((sarr[k]!=arr[k])&&(i==-1)) i = k;
        if((sarr[n-k-1]!=arr[n-k-1])&&(j==-1)) j = n-k-1;
    }
    bool win = true;
    for(int k = 0;k<=j-i;k++){
        if(sarr[i+k]!=arr[j-k]){
            win = false;
            break;
        }
    }
    if(i==j) win = true;
    if(win){
        cout << "yes" << endl;
        cout << max(0,i) + 1 << " " << max(0,j) + 1 << endl;
    }else cout << "no" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    
    return 0;
}
