class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR gives 1 at positions where bits differ
        int xorResult = start ^ goal;
        int count = 0;

        // Count the number of set bits in xorResult (i.e., the differing bits)
        while (xorResult) {
            count += xorResult & 1;
            xorResult >>= 1;
        }

        return count;
    }
};

