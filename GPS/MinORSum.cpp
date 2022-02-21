# include <bits/stdc++.h>
# define ll long long 
# define endl '\n'

using namespace std;

int32_t main(){

    int TC;
    cin >> TC;
    while (TC--) {
        
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n;i++) cin >> arr[i];
        //sort(arr,arr+n);
        ll ord = 0;
        for (int i = 0; i<n; i++){
            ord = ord|arr[i];
        }
        for (int i = 0;i<n-1;i++){
            arr[i] = ((ord&1)<<i) ;
            //ord ^= 1;
            ord >>= 1;
        }
        arr[n-1] = ord<<n-1;
        ll sum = 0;
        for (int i = 0; i<n ; i++) sum += arr[i];
        cout << sum << endl;
    }
}