ll exp(ll a, ll b)
{
    if (b == 0)
        return 1l;
    if (b % 2 == 1)
        return (a * exp(a, b - 1)) % MOD;

    ll r = exp(a, b / 2);
    return (r * r) % MOD;
}