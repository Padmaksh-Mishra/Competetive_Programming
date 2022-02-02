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
        ll N,K;
        string s ;
        cin >> N >> K;
        cin >> s;
        int i = 0;
        int max = *s.begin();
        if(max == 0) cout << 0 << endl;
        else if((10-max)<=K){
        for ( auto val : s){
            
            if (val < max){
                break;
            }
            if(val>=max){
                max = val;
                
            }
            i++;
        }
        cout << i << endl;
        }else cout << 0 << endl;
    }
    return 0;
}