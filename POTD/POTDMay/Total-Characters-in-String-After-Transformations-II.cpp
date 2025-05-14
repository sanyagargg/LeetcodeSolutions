class Solution {
public:
    using Matrix = vector<vector<long long>>;
    const int MOD = 1e9 + 7;

    Matrix multiply(Matrix& A, Matrix& B) {
        int n = 26;
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                if (A[i][k])
                    for (int j = 0; j < n; ++j)
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

    Matrix power(Matrix A, long long exp) {
        int n = 26;
        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) res[i][i] = 1; // identity
        while (exp) {
            if (exp % 2) res = multiply(res, A);
            A = multiply(A, A);
            exp /= 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // Step 1: Initial frequency vector
        vector<long long> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        // Step 2: Build the transformation matrix
        Matrix M(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int j = 1; j <= nums[i]; ++j)
                M[i][(i + j) % 26]++;

        // Step 3: Compute M^t using matrix exponentiation
        Matrix Mt = power(M, t);

        // Step 4: Multiply M^t * freq vector
        vector<long long> result(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                result[i] = (result[i] + Mt[j][i] * freq[j]) % MOD;

        // Step 5: Sum up the result
        long long total = 0;
        for (int i = 0; i < 26; ++i)
            total = (total + result[i]) % MOD;

        return static_cast<int>(total);
    }
};
