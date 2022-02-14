//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//iostream already included 

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        int n;
        cin >> n;
        int arry[n],b[n];
        for(int i = 0; i < n; i++) {
            cin >> arry[i];
            b[i] = arry[i];
        }
        sort(b,b+n);
        bool won = true;
        for(int i = 0; i < n; i++) {
            if(b[i] != arry[i]) {
                won = false;
                break;
            }
        }
        if(won == false) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}