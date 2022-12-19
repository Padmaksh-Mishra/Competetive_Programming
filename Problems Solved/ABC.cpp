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
        int N;
        string S;
        cin >> N >> S;
        if(N==2){
            if(S[0] != S[1]){
                cout << "YES\n";
            }else cout << "NO\n";
        }else if(N==1){
            cout << "YES\n";
        }else cout << "NO\n";
    }
    return 0;
}