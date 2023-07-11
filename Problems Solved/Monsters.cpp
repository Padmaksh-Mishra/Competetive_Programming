# include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m; cin >> n >> m;
	vector<string> mat(n);
	for(int i=0;i<n;++i) cin >> mat[i];

	queue<pair<int,int>> q;
	vector<vector<int>> dis(n,vector<int>(m,1e9));

	pair<int,int> ply = {-1,-1};
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mat[i][j]=='M'){
				dis[i][j] = 0;
				q.push(make_pair(i,j));
			}else if(mat[i][j]=='A'){
				ply.first = i; ply.second = j;
			}
		}
	}
	function<bool(int,int)> ok = [&](int x,int y){
		return (x<n&&y<m&&x>-1&&y>-1);
	};

	vector<pair<int,int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(auto move : moves){
			int xx = x + move.first;
			int yy = y + move.second;
			if(!ok(xx,yy)) continue;
			if(mat[xx][yy]=='#') continue;
			if(dis[xx][yy]>dis[x][y]+1){
				dis[xx][yy] = dis[x][y] + 1;
				q.push(make_pair(xx,yy));
			}
		}
	}

	vector<vector<pair<int,int>>> prev(n,vector<pair<int,int>>(m));
	q.push(ply);
	dis[ply.first][ply.second] = 0;
	// for(int i=0;i<n;++i){
	// 	for(int j=0;j<m;++j){
	// 		cout << dis[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(auto move : moves){
			int xx = x + move.first;
			int yy = y + move.second;
			if(!ok(xx,yy)) continue;
			if(mat[xx][yy]=='#') continue;
			if(dis[xx][yy]>dis[x][y]+1){
				dis[xx][yy] = dis[x][y] + 1;
				q.push(make_pair(xx,yy));
				prev[xx][yy] = make_pair(x,y);
			}
		}
		if(x==0||y==0||x==n-1||y==m-1){
			int fx = x,fy = y;
			string ans = "";
			while(dis[fx][fy]){
				if(fx-prev[fx][fy].first==-1) ans+='U';
				if(fx-prev[fx][fy].first==1) ans+='D';
				if(fy-prev[fx][fy].second==-1) ans+='L';
				if(fy-prev[fx][fy].second==1) ans+='R';
				int tx = prev[fx][fy].first;
				int ty = prev[fx][fy].second;
				fx = tx;
				fy = ty;
			}
			
			cout << "YES" << endl;
			cout << ans.size() << endl;
			reverse(ans.begin(),ans.end());
			cout << ans << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}