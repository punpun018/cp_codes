// dfs function part
void dfs(int cur, int par)
{
    col[cur] = 1; // gray
    for (auto it : g[cur])
    {
        if (col[it] == 1)
        {
            // found a cycle
            ;
        }
        if (col[it] == 0)
            dfs(it, cur);
    }
    col[cur] = 2 // black
}

// main loop part
for (int i = 1; i <= n; i++)
{
    if (col[i] == 0)
        dfs(i, 0); // if node is white start new dfs
}