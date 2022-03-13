//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int n,ip;
        ll x=0;
        cin >> n;
        for(int i = 0; i <n;i++){
            cin >> ip;
            x+=ip;
        }
        cout << !(x%n ==0) << endl;
        
    }
    return 0;
}
