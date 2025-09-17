ll count_beauty(const vec<ll>& a) {
    ll total_beauty = 0;
    for (ll x : a) {
        total_beauty += __builtin_popcountll(x);
    }
    return total_beauty;
}