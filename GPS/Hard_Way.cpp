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
        pair<int,int> A; cin >> A.first >> A.second;
        pair<int,int> B; cin >> B.first >> B.second;
        pair<int,int> C; cin >> C.first >> C.second;
        ll length = 0;
        if((A.second == B.second)&&(B.second)&&(C.second<A.second)) length = abs(A.first - B.first);
        else if((B.second == C.second)&&(B.second)&&(A.second<B.second)) length = abs(B.first - C.first);
        else if((A.second == C.second)&&(A.second)&&(B.second<C.second)) length = abs(A.first - C.first);
        cout << length << endl;
    }
    return 0;
}
