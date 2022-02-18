
# include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TT;
    cin >> TT;
    while(TT--){
        string s;
        cin >> s;
        int f[s.length()+1];
        f[0]=0;
        f[1]=0;
        
        for (int i = 1; i < s.length(); i++)
        {
            //cout << f[i] << endl;
            if(s.at(i-1)!=s.at(i)){
                f[i+1] = f[i] + 1;
                f[i+2] = f[i+1];
                i++;
                //cout << i << endl;
            }else f[i+1] = f[i];
            
        }
        cout << f[s.length()] << endl;
    }
    return 0;
}
