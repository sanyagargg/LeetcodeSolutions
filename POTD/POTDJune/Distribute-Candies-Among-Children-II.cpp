class Solution {
public:
    long long distributeCandies(int n, int limit) {
        const int limitPlusOne = limit + 1;
        const long oneChildExceedsLimit = ways(n - limitPlusOne);
        const long twoChildrenExceedLimit = ways(n - 2 * limitPlusOne);
        const long threeChildrenExceedLimit = ways(n - 3 * limitPlusOne);
        
        // Principle of Inclusion-Exclusion (PIE)
        return ways(n) - 3 * oneChildExceedsLimit + 3 * twoChildrenExceedLimit - threeChildrenExceedLimit;
    }

private:
    // Returns the number of ways to distribute n candies to 3 children
    long ways(int n) {
        if (n < 0) return 0;
        return nCk(n + 2, 2);
    }

    // Computes combinations: n choose k
    long nCk(int n, int k) {
        long res = 1;
        for (int i = 1; i <= k; ++i)
            res = res * (n - i + 1) / i;
        return res;
    }
};
