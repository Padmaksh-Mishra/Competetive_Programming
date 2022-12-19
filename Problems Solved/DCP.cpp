//Coding_Duck PM

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'

const ll MOD = 1e9 +7;
using namespace std;

int32_t main() {

	    map<int,ll> rxnMap;
	    int N,M;cin >> N >> M;
	    for(int i = 0;i<N;i++){
	        ll ip;
	        cin >> ip;
	        //ip %=MOD;
	        rxnMap[i] = ip;
	    }
	    for(int i = 0;i<M;i++){
	        int dcp;cin >> dcp;
	        int x;cin >> x;
	        for (int j = 0; j < x; j++) {
	            int w,c;cin >> w >> c;
	            rxnMap[c-1] = (rxnMap[c-1] + ((rxnMap[dcp-1]%MOD)*w)%MOD)%MOD; 
	        }
	        rxnMap[dcp-1] = 0;
	    }
	    for(int i = 0;i<N;i++){
	        cout << rxnMap[i] << "\n";
	    } 
		cout << endl;

	return 0;
}
