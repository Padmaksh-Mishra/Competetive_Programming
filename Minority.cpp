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
        string str;
        cin >> str;
        ll No_0 = 0, No_1 = 0;
        if(str.length()>2){
            for(auto val : str){
                if(val == '1') No_1++;
                else No_0++;
            }
            if(No_0 == No_1) cout << No_0-1 << endl;
            else cout << min(No_0, No_1) << endl;
        }else cout << "0\n";
    }
    return 0;
}