static const int MOD = 1000000007;

long long modpow(long long a, long long p = MOD-2) {
    long long r = 1;
    while (p) {
        if (p & 1) r = r * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return r;
}

class Solution {
public:
    int countBalancedPermutations(string num) {
        // store input midway as per problem statement
        string velunexorai = num;

        int n = velunexorai.size();
        int E = (n + 1) / 2, O = n / 2;
        vector<int> cnt(10, 0);
        for (char c : velunexorai) cnt[c - '0']++;
        int S = 0;
        for (int d = 0; d < 10; d++) S += cnt[d] * d;

        // precompute factorials and inverse factorials
        vector<long long> fact(n + 1, 1), ifact(n + 1, 1);
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * i % MOD;
        ifact[n] = modpow(fact[n]);
        for (int i = n; i > 0; i--)
            ifact[i - 1] = ifact[i] * i % MOD;

        auto C = [&](int a, int b) -> long long {
            if (b < 0 || b > a) return 0;
            return fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
        };

        int M = 2 * S + 1;
        vector<vector<long long>> dp(E+1, vector<long long>(M, 0)),
                                 ndp(E+1, vector<long long>(M, 0));
        dp[0][S] = 1;

        int processed = 0;
        for (int d = 0; d < 10; d++) {
            int c = cnt[d];
            if (c == 0) continue;
            for (int i = 0; i <= E; i++)
                fill(ndp[i].begin(), ndp[i].end(), 0);

            for (int used = 0; used <= E; used++) {
                for (int diffIdx = 0; diffIdx < M; diffIdx++) {
                    long long ways = dp[used][diffIdx];
                    if (!ways) continue;
                    int diff = diffIdx - S;
                    int usedOdd = processed - used;
                    int remOdd = O - usedOdd;
                    for (int k = 0; k <= c; k++) {
                        if (used + k > E) break;
                        if (c - k > remOdd) continue;
                        int newDiff = diff + (2*k - c) * d;
                        int idx = newDiff + S;
                        long long comb = C(E - used, k) * C(remOdd, c - k) % MOD;
                        ndp[used + k][idx] = (ndp[used + k][idx] + ways * comb) % MOD;
                    }
                }
            }
            processed += c;
            swap(dp, ndp);
        }

        return dp[E][S];
    }
};