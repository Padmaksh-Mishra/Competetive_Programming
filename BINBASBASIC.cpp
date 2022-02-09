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
        string binstr;
        cin >> binstr;
        ll count = 0;
        for(int i =0 ; i<N/2 ; i++){
            if(binstr[i]!=binstr[N-1-i]) count++;
        }
        //cout << count << endl;
        // if(count == K) cout << "YES" << endl;
        // else if((K-count)&1==0) cout << "YES" << endl;
        // else if ((N%2!=0)&&(K-count+1>=0)) cout << "YES" << endl;
        // else cout << "NO" << endl;
        if((K<count)||((N%2==0)&&(K-count)%2!=0)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}