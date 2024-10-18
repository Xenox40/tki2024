#include <iostream>
#include <vector>
using namespace std;

const int N = 1001000;

vector<vector<int>> g(N);
pair<int,int> lowest_child[N]; // {odleglosc, id}

int a1,a2,longest_path=0;

void dfs(int s, int p)
{
    lowest_child[s]={0,s};
    pair<int,int> lowest_child2={0,s};
    for(auto u : g[s]) if(u!=p)
    {
        dfs(u,s);
        if(lowest_child[u].first+1 >= lowest_child[s].first)
        {
            lowest_child2=lowest_child[s];
            lowest_child[s]={lowest_child[u].first+1,lowest_child[u].second};
        }
        else if(lowest_child[u].first+1 > lowest_child2.first)
        {
            lowest_child2={lowest_child[u].first+1,lowest_child[u].second};
        }
    }
    if(lowest_child[s].first+lowest_child2.first> longest_path)
    {
        longest_path = lowest_child[s].first+lowest_child2.first;
        a1 = lowest_child[s].second;
        a2 = lowest_child2.second;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1; i < n; i ++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    a1=1;
    a2=1;
    dfs(1,1);
    cout<<longest_path;
}
