const int NN = 1e7 + 5;
int mind[NN];
// mind[i] contains the smallest prime factor of i

void precal()
{
    for (int i = 1; i < NN; i++)
        mind[i] = i;
    for (int p = 2; p < NN; p++)
    {
        if (mind[p] != p)
            continue;
        for (int d = p * 2; d < NN; d += p)
            mind[d] = min(mind[d], p);
    }
}

// getpr(x) is used to get the vector of all the prime factors
vector<int> getpr(int x)
{
    vector<int> v;
    while (x > 1)
    {
        if (v.empty() || v.back() != mind[x])
            v.push_back(mind[x]);
        x /= mind[x];
    }
    return v;
}