class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int MOD = 1'000'000'007;

        // Precompute factorials and inverse factorials
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        invFact[n] = modInverse(fact[n], MOD);
        for (int i = n - 1; i >= 0; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }

        // Calculate combinations C(n-1, k)
        long long comb = fact[n - 1] * invFact[k] % MOD * invFact[n - 1 - k] % MOD;

        // Calculate the number of good arrays
        long long result = m * modPow(m - 1, n - k - 1, MOD) % MOD * comb % MOD;
        return result;
    }

private:
    // Modular exponentiation
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }

    // Modular inverse using Fermat's Little Theorem
    long long modInverse(long long a, int mod) {
        return modPow(a, mod - 2, mod);
    }
};
