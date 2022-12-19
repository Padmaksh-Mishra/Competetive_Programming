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
    ll prod = 1;
    int zero = -1;
    for(int i= 0; i < n; i++){
        cin >> arr[i];
        if(arr[i]==0) zero = i;
        prod = prod * arr[i];
    }
    if(prod>0) cout << 0 << " " << 0 << endl;
    else if(prod==0) {
        ll left = 1,right = 1;
        ll prod = 1;
        int begin = 0,hyper = 0;
        int end = 0;
        int maxp = -1e9;
        pair<int,int> ans;
        //map<ll,pair<int,int>> mp;
        for(int i = 0; i<n; i++){
            if(arr[i]!=0) prod = prod * arr[i];
            else {
                if(prod>maxp) {
                    maxp = prod;
                    ans = {begin,end};
                    prod = 1;
                } 
                begin = i;
            }
        }
        // auto it = mp.begin();
        // int tmp = (*it).second.first;
        // if(tmp==0) cout << (*it).second.second - tmp + 1 << " " << 0 << endl;
        // else cout << 0 << " " << (*it).second.second - tmp + 1 << endl;
        int lft =0,rit = 0;
        if(ans.first!=0) lft = ans.first;
        if(ans.second!=n-1) rit = ans.second;
        cout << lft+1 << " " << rit-1 << endl;
        // for(int i=0; i < zero; i++) left = left*arr[i];
        // for(int i = zero+1;i<n;i++) right = right*arr[i];
        // if(left>=right) cout << 0 << " " << n-zero+1 << endl;
        // else cout << zero+1 << " " << 0 << endl;
    }else {
        int i = 0;
        ll left = 1;
        while(left > 0){
            left = left*arr[i];
            i++;
        }
        ll right = 1;
        i=n-1;
        while(right > 0){
            right = right*arr[i];
            i--;
        }
        if(left<=right) cout << 0 << " " << n-i-1 << endl;
        else cout << i << " " << 0 << endl;
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
