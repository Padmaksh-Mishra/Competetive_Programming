//Name.Redacted || Coding_Duck || PM

# include <bits/stdc++.h>	//ioseam already included 

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC; 
    while(TC--){
        int N;
        string s;
        cin >> N;
        cin >> s;
        sort(s.begin(), s.end());
        map<char,int> mymap;
        for(auto val : s){
            if(mymap.find(val) != mymap.end()) mymap[val]++;
            else mymap[val] = 1;
        }
        ll max = 1;
        char ch;
        for (auto val : mymap){
            if(max<val.second){
                max = val.second;
                ch = val.first; 
            }
        }
        if((N%2==0)&&(max<=(N/2))){
            cout << "YES" << endl;
            for(int i = 0; i < N/2;i++) cout << s[i];
            for(int i = N-1; i >=N/2;i--) cout << s[i];
            cout << endl;
        }else cout << "NO" << endl;
    }
    return 0;
}