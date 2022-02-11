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
        cin >> N >> K;
        ll ans = K - N;
        ll temp = 0;
        for(int i = 1 ;i<=N;i++){
            ll jadu = i*(i+1)/2;
            if(jadu>K) {
                temp = i-1;
                break;
            } 
        }
        ans = ans - temp;
        vector<int> V;
        V.push_back(1);
        for(int i = 1;i<=temp;i++){
            V.push_back(i);
        }
        ll j =0;
        while(V.size()<ans){
            V.push_back(V[j]);
            j++;
        }
        while(V.size()<N){
            V.push_back(V[0]);
        }
        for(auto val : V){
            cout << val << " ";
        }
    }
    return 0;
}