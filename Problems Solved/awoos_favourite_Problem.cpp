# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e8 +7;
using namespace std;

void solve(){
    int n; cin >> n;
    string s,t; cin >> s >> t;
    long long count_as=0,count_bs=0,count_cs=0,count_at=0,count_bt=0,count_ct=0;
    vector<int> as,at,cs,ct;
    for(int i=0;i<n;i++){
        if(s[i]=='a') count_as++;
        if(s[i]=='b') count_bs++;
        if(s[i]=='c') count_cs++;
        if(t[i]=='a') count_at++;
        if(t[i]=='b') count_bt++;
        if(t[i]=='c') count_ct++;
        if(s[i]=='a') as.push_back(i);
        if(t[i]=='a') at.push_back(i);
        if(s[i]=='c') cs.push_back(i);
        if(t[i]=='c') ct.push_back(i);
    }
    vector<char> ns,nt;
    for(int i=0;i<n;++i){
        if(s[i]!='b') ns.push_back(s[i]);
        
    }
    for(int i=0;i<n;++i){
        if(t[i]!='b') nt.push_back(t[i]);
    }
    
    if(count_at!=count_as){
        cout << "NO" << endl;
        return;
    }
    if(count_bt!=count_bs){
        cout << "NO" << endl;
        return;
    }
    if(count_ct!=count_cs){
        cout << "NO" << endl;
        return;
    }

    for(int i=0;i<as.size();++i){
        //deb(as[i]);
        if(as[i]>at[i]){
            cout << "NO" << endl;
            return;
        }
    }

    for(int i=0;i<cs.size();++i){
        if(cs[i]<ct[i]){
            cout << "NO" << endl;
            return;
        }
    }
    for(int i=0;i<ns.size();++i){
        // deb(ns[i]);
        // deb(nt[i]);
        if(ns[i]!=nt[i]){
            cout << "NO" << endl;
            return;      
        } 
    }
    cout << "YES" << endl;
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}