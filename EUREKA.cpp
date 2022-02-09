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
        ll N;
        cin >> N;
        double ans = pow((0.143*N),N);
        ll a = ans;
        if(ans-a>0.5) cout << a+1 << endl;
        else cout << a << endl;
    }
    return 0;
}