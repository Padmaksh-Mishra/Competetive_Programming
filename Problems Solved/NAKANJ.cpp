# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;
int level[8][8];
int visited[8][8];
vector<pair<int,int>> movements = {
	{2,-1},{2,1},
	{-2,-1},{-2,1},
	{1,2},{-1,2},
	{1,-2},{-1,-2},
};

void reset(){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			level[i][j]=visited[i][j]=0;
		}
	}
}
int isOk(int x , int y){
	return (x>=0&&x<8&&y>=0&&y<8);
}
int getX(string w){
	return w[0]-'a';
}
int getY(string w){
	return w[1]-'1';
}

int bfs(string st,string e){
	int sourceX = getX(st);
	int sourceY = getY(st);
	int endX = getX(e);
	int endY = getY(e);
	queue<pair<int,int>> q;
	q.pb({sourceX,sourceY});
	visited[sourceX][sourceY]=1;
	while(!q.empty()){
		int x = q.front().f;
		int y = q.front().s;
		q.pop();
		for(auto move : movements){
			int nx = x + move.f;
			int ny = y + move.s;
			if(!isOk(nx,ny)||visited[nx][ny]) continue;
			visited[nx][ny]=1;
			level[nx][ny] = level[x][y] + 1;
			q.pb({nx,ny});
		}
	}
	return level[endX][endY];
}

void solve(){
	reset();
	string st,e; cin >> st >> e;
	cout << bfs(st,e) << endl;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 