//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //cout << (27+25)%27 << endl; 
    //cout << (int)'a' << endl;
    int TC;
    cin >> TC;
    while(TC--){
        int N,Q; cin >> N >> Q;
        string A,B; cin >> A >> B;
        int ops[N];
        for(int i=0;i<N;i++){
            ops[i] = (A[i]-B[i]+26)%26;
        }
        int diffrences[N];
        for(int i=0;i<N;i++){
            diffrences[i] = (A[i]-B[i]+26)%26;
        }
        while(Q--){
            int L,R; cin >> L >> R;
            int a = 0;
            for(int i=L-1;i<R;i++){
                if(i&1) a = a + diffrences[i];
                else a = (a-diffrences[i]+26)%26;
                ///cout << "a is = " << a << endl;
            }
            if(a) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}
