function<void(int)> dfs = [&](int cur)
    {
        vis[cur] = true;
        for (auto it : adj[cur])
        {
            if (!vis[it])
                dfs(it);
        }
    };
