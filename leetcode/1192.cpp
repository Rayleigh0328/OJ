#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

#define N 100001

class Solution {
public:

vector<int>G[N];
bool visit[N];
int dfn[N];
int low[N];
int parent[N];

int min(int a, int b)
{
    if (a < b) return a;
    else return b;
}

void input(int n, vector<vector<int>> edges)
{
    int a, b;
    for (auto edge : edges)
    {
        a = edge[0]; 
        b = edge[1];
        G[a].push_back(b);/*邻接表储存无向边*/
        G[b].push_back(a);
    }
}

void dfs(int u, vector<vector<int>>& ret)
{
    //记录dfs遍历次序
    static int counter = 0;
    //记录节点u的子树数
    int children = 0;
    visit[u] = true;
    //初始化dfn与low
    dfn[u] = low[u] = ++counter;
    for (int j = 0; j < G[u].size(); j++)//遍历与u相连的顶点
    {
        int v = G[u][j];
        if (!visit[v])
        {
            children++;
            parent[v] = u;//u是v的父节点
            dfs(v, ret);//深度优先搜索v
            low[u] = min(low[u], low[v]);//等v完成深度优先搜索之后，low[u]记录节点u或u的子树通过非父子边追溯到最早的祖先节点（即DFS次序号最小）
//            if (parent[u] == -1 && children > 1)//对根节点u，若其有两棵或两棵以上的子树，则该根结点u为割点；
//            {
//                cout << "1 articulation point: " << u<<endl;
//            }
//            if (parent[u] != -1 && low[v] >= dfn[u])//对非叶子节点u（非根节点），若其子树的节点均没有指向u的祖先节点的回边（条件low[v] >= dfn[u]表达的就是），说明删除u之后，根结点与u的子树的节点不再连通；则节点u为割点。
//            {
//                cout << "2 articulation point: " << u << endl; //这样做，可能出现某个顶点多次输出，其实可以用一个指示变量来指示，做到顶点不重复输出
//            }
            if (low[v] >dfn[u]) //桥的条件
            {
                //cout << "Bridge " << v << " " << u << endl;
                vector<int> tmp_edge{u,v};
                ret.push_back(tmp_edge);
            }

        }
        else if (v != parent[u]) {//节点v已访问，则(u,v)为回边,且不是重边
            low[u] = min(low[u], dfn[v]);
        }
    }

}

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) { 
        memset(dfn, -1, sizeof(dfn)); 
        memset(low, -1, sizeof(low)); 
        memset(visit, false, sizeof(visit)); 
        memset(parent, -1, sizeof(parent));
        input(n, connections);
        vector<vector<int>> result;
        dfs(1, result);
        return result;
    }
};
