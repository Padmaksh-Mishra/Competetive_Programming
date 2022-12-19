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
        int N,no_0 = 0,no_1 = 0;
        cin >> N;
        string binStr;
        cin >> binStr;
        for (auto it = binStr.begin(); it != binStr.end(); ++it){
            if(*it == '0') no_0++;
            else no_1++;
        }
        //cout << "Processing finished ZERO = " << no_0 << " ONE = " << no_1 << endl;
        if(N&1){    //N is odd
            //cout << "N is odd" << endl;
            if(abs(no_0-no_1)&1){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }else {
            //cout << "N is even" << endl;
            if(no_0==no_1){
                cout << "YES" << endl;
            } 
            else if((no_0&1)&&(no_1&1)) cout << "NO" << endl;
            
            else cout << "YES" << endl;
        }
    }
    return 0;
}