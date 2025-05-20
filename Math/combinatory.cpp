using ll = long long;
const int MAXN = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll factorial[MAXN];

ll exp(ll a, ll b)
{
    if (b == 0)
        return 1l;
    if (b % 2 == 1)
        return (a * exp(a, b - 1)) % MOD;

    ll r = exp(a, b / 2);
    return (r * r) % MOD;
}

void build_factorials()
{
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        factorial[i] = factorial[i - 1] * i % MOD;
    }
}
ll binomial_coefficient(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    ll denom = factorial[k] * factorial[n - k] % MOD;
    return factorial[n] * exp(denom, MOD - 2) % MOD;
}
