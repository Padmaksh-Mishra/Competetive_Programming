//Coding_Duck PM

# include <iostream>
# include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT; 
    while(TT--){
        int N;
        cin >> N;
        vector<int> V;
        for(int i = 0; i < N;i++){
            int inp;
            cin >> inp;
            auto x = upper_bound(V.begin(),V.end(),inp);
            
            if(x == V.end()){
                V.push_back(inp);
            }else{
                *(x) = inp;
            }
        }
        cout << V.size() << " ";
        for(auto i = V.begin(); i != V.end();i++){
            cout << *i << " "; 
        }
        cout << endl;
    }
    return 0;
}