//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int n; cin >> n;
        int arry[n];
        ll sum_T = 0,sum_B = 0;
        for(int i=0; i<n; i++){
            cin >> arry[i];
            sum_T += arry[i];
        }
        sort(arry,arry+n);
        int i=0;
        ll sumBlue = arry[0] , sumRed = 0;
        while(true){
            sumBlue += arry[i+1];
            sumRed += arry[n-i-1];
            if(sumRed>sumBlue) {
                cout << "YES" << endl;
                break;
            }
            i++;
            if(i>n/2) {
                cout << "NO" << endl;
                break;
            }
        }
    }
    return 0;
}
