void update_bits_and_sum(long mask, vec<int> &bits_used, long long &sum) {
    for (long j = mask; j > 0; j &= j - 1) {
        int bit = __builtin_ctzll(j);  // lowest bit ON (0-index)
        if (bits_used[bit] == 0) {
            sum += (1LL << bit);
        }
        bits_used[bit]++;
    }
}