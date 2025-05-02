class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0; // Base case
        long long N = n; // Convert to long long to handle INT_MIN case
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double ans = 1.0;
        while (N > 0) {
            if (N % 2 == 1) ans *= x; // If n is odd, multiply x once
            x *= x; // Square the base
            N /= 2; // Reduce n by half
        }
        return ans;
    }
};


//binary exponentiation approach
//time : O(logn), space : O(1)