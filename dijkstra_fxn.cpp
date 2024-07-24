const int NN = 1e5 + 5;
vector<vector<pair<int, int>>> adj(NN);
vector<int> dist(NN, intmax);
vector<int> par(NN);
vector<bool> vis(NN);

void dijkstra(int source)
{
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, source});
    while (!q.empty())
    {
        int node = q.top().second;
        q.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        for (auto child : adj[node])
        {
            int len = child.second;
            if (dist[child.first] < dist[node] + len)
                continue;
            dist[child.first] = dist[node] + len;
            par[child.first] = node;
            q.push({dist[child.first], child.first});
        }
    }
}