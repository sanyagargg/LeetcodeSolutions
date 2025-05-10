class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to avoid overflow and take absolute values
        long long dvd = static_cast<long long>(dividend);
        long long dvs = static_cast<long long>(divisor);

        // Determine the sign
        bool isNegative = (dvd < 0) ^ (dvs < 0);

        dvd = abs(dvd);
        dvs = abs(dvs);

        long long result = 0;

        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }

        result = isNegative ? -result : result;
        return result;
    }
};
