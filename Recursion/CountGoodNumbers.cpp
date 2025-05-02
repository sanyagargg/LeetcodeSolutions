class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        long long power(long long base, long long exp, long long mod) {
            long long result = 1;
            base %= mod;
            while (exp > 0) {
                if (exp % 2 == 1)
                    result = (result * base) % mod;
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        }
    
        int countGoodNumbers(long long n) {
            long long even_count = (n + 1) / 2;
            long long odd_count = n / 2;
    
            long long even_ways = power(5, even_count, MOD); // even indices: 0, 2, 4, ...
            long long odd_ways = power(4, odd_count, MOD);   // odd indices: 1, 3, 5, ...
    
            return (even_ways * odd_ways) % MOD;
        }
    };
    
    
    //Time	O(log n)
    // Space	O(1)