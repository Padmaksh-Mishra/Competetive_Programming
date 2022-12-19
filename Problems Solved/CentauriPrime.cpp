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
    ll i = 0;
    while(TC--){
        i++;
        string ip;
        cin >> ip;
        set<char> set = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        if(set.find(*(ip.end()-1)) != set.end()) cout << "CASE #" << i << ": " << ip << " is ruled by Alice." << endl;
        else if (*(ip.end()-1)=='y') cout << "CASE #" << i << ": " << ip << " is ruled by nobody." << endl;
        else cout << "CASE #" << i << ": " << ip << " is ruled by Bob." << endl; 
    }
    return 0;
}