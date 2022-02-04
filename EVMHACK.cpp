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
        int A,B,C,P,Q,R;
        cin >> A >> B >> C >> P >> Q >> R;
        int w = (P+Q+R)/2;
        bool won = false;
        int v;
        if(!won){
            v = P+B+C;
            if(v>w) won = true;
        }
        if(!won){
            v = A+Q+C;
            if(v>w) won = true;
        }
        if(!won){
            v = A+B+R;
            if(v>w) won = true;
        }
        if(won) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}