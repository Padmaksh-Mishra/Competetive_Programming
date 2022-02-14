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
        ll N,temp,ops = 0;
        cin >> N;
        vector<ll> V;
        for(int i = 0; i < N;i++){
            cin >> temp;
            V.push_back(temp);
            if(V[i] == i+1+ops) ops++;
        }
        cout << ops << endl;
    }
    return 0;
}