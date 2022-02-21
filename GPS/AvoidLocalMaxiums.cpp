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
        ll ops = 0;
        for (int i=0; i<n; i++) cin >> arr[i];
        for (int i=1; i<n-1; i++) {
            if((arr[i] > arr[i+1])&&(arr[i] > arr[i-1])){
                ops++;
                arr[i] = min(arr[i+1],arr[i-1]);
            }
        }
        cout << ops << endl;
        for (int i=0; i<n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}