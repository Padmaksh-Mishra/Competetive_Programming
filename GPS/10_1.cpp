#include<bits/stdc++.h>
using namespace std;

int findParent(int x, vector<int> &parent)
{
	if (x == parent[x])
	{
		return x;
	}

	return (parent[x] = findParent(parent[x], parent));
}

void unionIt(int x, int y, vector<int> &rank, vector<int> &parent)
{
	int parentX = findParent(x, parent), parentY = findParent(y, parent);

	if (parentX == parentY)
	{
		return;
	}

	if (rank[parentX] > rank[parentY])
	{
		swap(parentX, parentY);
	}

	parent[parentX] = parentY;

	if (rank[parentX] == rank[parentY])
	{
		rank[parentY]++;
	}
}

int getMST(const int n, const vector<vector<int>>& edges, int blockedge, int preEdge = -1)
{
	vector<int> parent, rank;

	rank = vector<int>(n, 1);

	parent.resize(n);

	for (int i = 0; i < n; ++i)
	{
		parent[i] = i;
	}

	int weight = 0;

	if (preEdge != -1)
	{
		weight += edges[preEdge][2];
		unionIt(edges[preEdge][0], edges[preEdge][1], rank, parent);
	}

	for (int i = 0; i < edges.size(); ++i) {
		if (i == blockedge)
		{
			continue;
		}

		const auto& edge = edges[i];
		if (findParent(edge[0], parent) == findParent(edge[1], parent))
		{
			continue;
		}

		unionIt(edge[0], edge[1], rank, parent);
		weight += edge[2];
	}

	for (int i = 0; i < n; ++i)
	{
		if (findParent(i, parent) != findParent(0, parent))
		{
			return 1e9 + 7;
		}
	}

	return weight;
}


int main()
{

    vector<vector<int>>edges; //store input
    
    int n;
    cin >> n;
    
    

    string s;
    cin >> s; // input as string as per input instructions

    if( n  >100 ){ cout<<"Please enter n between 2 to 100";return 0;} //error message

    vector<vector<int>> v;

    int m = v.size();
    int arr[3] = {0};
    int k = -1;
    for (int i = 1; i < s.size() - 1; i++)  // more processable input form
    {
        if (s[i] == '[' || s[i] == ']' || s[i] == ',')
        {
            continue;
        }

        else if (s[i] >= 48 && s[i] <= 57)
        {
            k++;
            vector<int> a;
            int var = i, x, y, w, j = 0;
            while (s[i] != ']')
            {
                if (s[i] == ',')
                {
                    i++;
                    a.clear();
                    var = i;
                    continue;
                }
                else if (s[i + 1] >= 48 && s[i + 1] <= 57)
                {
                    
                    a.push_back((s[i] - '0'));
                    i++;
                }

                else
                {
                   
                    a.push_back((s[i] - '0'));
                    i++;
                    
                    var = i;
                    
                    for (int p = a.size()-1,z = 0; p > -1; p--,z++)
                    {
                        arr[j] += a[p] * pow(10, z);
                    }
                    a.clear();
                    j++;
                }
            }
           
            vector<int> v1;
            v1.push_back(arr[0]);
            v1.push_back(arr[1]);
            v1.push_back(arr[2]);
            v.push_back(v1);
            arr[0] = arr[1] = arr[2] = 0;
        }
    }
     
    edges=v; // copying

	for (int i = 0; i < edges.size(); ++i)
	{
		edges[i].push_back(i);
	}

	sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
		return a[2] < b[2];
	});

	int minWt = getMST(n, edges, -1);

	vector<int> critical, pseudoCritical;

	for (int i = 0; i < edges.size(); ++i)
	{
		if (minWt < getMST(n, edges, i))
		{
			critical.push_back(edges[i][3]);
		}
		else if (minWt == getMST(n, edges, -1, i))
		{
			pseudoCritical.push_back(edges[i][3]);
		}
	}
	

    // as per output

     cout<<"[[";
     for(int k=0;k<critical.size();k++)
     {
        cout<<critical[k]<<",";
     }
     cout<<"],[";
     for(int k=0;k<pseudoCritical.size();k++)
     {
        cout<<pseudoCritical[k]<<",";
     }
     cout<<"]]";
}

