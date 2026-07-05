#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;

int parent[N];
int sz[N];

struct Edge
{
    int u, v, w;
};

vector<Edge> edges;

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

int Find(int node)
{
    if (parent[node] == node)
        return node;

    return parent[node] = Find(parent[node]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}

int main()
{
    int n, m;
    cin >> n >> m;

    int full_cost = 0;

    vector<Edge> routes;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++)
    {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        full_cost += e.w;
        edges.push_back(e);
    }

    sort(edges.begin(), edges.end(), cmp);

    int totalCost = 0;
    int edgeCount = 0;

    for (Edge e : edges)
    {
        if (Find(e.u) != Find(e.v))
        {
            Union(e.u, e.v);
            routes.push_back({e.u, e.v, e.w});
            totalCost += e.w;
            edgeCount++;
        }
    }

    int sd = m - edgeCount;
    int savings = full_cost - totalCost;

    if (edgeCount != n - 1)
        cout << "IMPOSSIBLE\n";
    else
    {

        cout << "Routes shut down: " << sd << endl;
        cout << "Total savings: " << savings << endl;

        cout << "operational routes: \n";

        for (Edge e : routes)
        {
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }

    return 0;
}
