# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define all(x) (x).begin(), (x).end()

using namespace std;
void make(int n,vector<int> &parent,vector<int> &size){
        for(int i=0;i<n;++i){
            parent[i] = i;
            size[i] = 1;	
        }
    }

    int findParent(int u,vector<int> &parent){
        if(u==parent[u]){
            return u;
        }
        return parent[u] = findParent(parent[u],parent);
    }

    void Union(int a,int b,vector<int> &parent,vector<int> &size){
        a = findParent(a,parent);
        b = findParent(b,parent);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[a] = b;
            size[a]+=size[b];
        }	
    }
    static bool comp(vector<int> a,vector<int> b){
        return a[1] < b[1];
    }
vector <int> edge;
void extractIntegerWords(string str)
{
    stringstream ss;
 
    ss << str;
 
    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {
 
        /* extracting word by word from stream */
        ss >> temp;
 
        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found)
        edge.push_back(found);
        /* To save from space at the end of string */
        temp = "";
    }
}
int main(){
	
	int n; cin >> n;
    string s;
    cin>>s;
	vector<vector<int>> graph,edges;
    vector<int> parent(n+2),size(n+2);
    int min_wt = 0;
    vector<int> critical,psudo_critical;
    
    extractIntegerWords(s);
    int no_edg = (edge.size()/3);
    for (int i=0;i<no_edg;i++)
    {
        int u,v,w;
        u=edge[3*i];
        v=edge[3*i+1];
        w=edge[3*i+2];
        edges.push_back({u,v,w});
        
    }
    for(int i=0;i<edges.size();++i){
        graph.push_back({i,edges[i][0],edges[i][1],edges[i][2]});
    }
    sort(graph.begin(),graph.end(),comp);

    make(n,parent,size);
    for(auto val : graph){
        int a=val[2],b=val[3];
        if(findParent(a,parent)!=findParent(b,parent)){
            min_wt+=val[1];
            Union(a,b,parent,size);
        }
    }
    
    //reset parent and size
    make(n,parent,size);
    //finding critical edges
    for(int i=0;i<edges.size();++i){
        int new_wt = 0;
        for(int j=0;j<edges.size();++j){
            if(i==j) continue;
            int a=graph[j][2],b=graph[j][3];
            if(findParent(a,parent)!=findParent(b,parent)){
                new_wt+=graph[j][2];
                Union(a,b,parent,size);
            }		
        }
        if(new_wt>min_wt){
            critical.push_back(graph[i][0]);
        }
    }

    //reset parent and size
    make(n,parent,size);
    //finding psudo critical edges
    for(int i=0;i<edges.size();++i){
        int new_wt=graph[i][1];
        Union(graph[i][2],graph[i][3],parent,size);
        for(int j=0;j<edges.size();++j){
            if(i==j) continue;
            int a=graph[j][2],b=graph[j][3];
            if(findParent(a,parent)!=findParent(b,parent)){
                new_wt+=graph[j][2];
                Union(a,b,parent,size);
            }		
        }
        if(new_wt==min_wt){
            psudo_critical.push_back(graph[i][0]);
        }
    }
    cout << "[[";
    for(auto val : critical){
    	cout << val << ",";
    }
    cout << "]";
    for(auto val : psudo_critical){
    	cout << val << ",";
    }
    cout << "]";
   	return 0;     
}