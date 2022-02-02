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
        ll n;
        cin >> n;
        for(int i = 0; i < 10;i++){
            if(n%7==0){
                break;
            }
            n = (n/10)*10 +i;
        }
        cout << n << endl;
    }
    return 0;
}