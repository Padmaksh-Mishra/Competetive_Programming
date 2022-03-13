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

    int TC;
    cin >> TC;
    while(TC--){
        int N; cin >> N;
        int A[N],B[N];
        for(int i=0 ; i<N ; i++) cin >> A[i];
        for(int i=0 ; i<N ; i++) cin >> B[i];
        //check straight cost 
        ll costSt = abs(A[0] - B[0]) + abs(A[N-1] - B[N-1]);
        //check cross cost
        ll costX =(ll)abs(A[0]-B[1])+(ll)abs(A[1]-B[0])+(ll)abs(A[N-1]-B[N-2])+(ll)abs(A[N-2]-B[N-1]);
        if(costX<0) cout << costSt << endl;
        else cout << min(costX,costSt) << endl;
    }
    return 0;
}
