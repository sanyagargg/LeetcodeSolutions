class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
    // Check if the number of cards in hand is divisible by groupSize
    if (hand.size() % groupSize != 0) {
        // If not, it's impossible to form groups of groupSize
        return false;
    }

    // Map to store the count of each card
    std::map<int, int> count;

    // Count the occurrences of each card in the hand
    for (int card : hand) {
        count[card]++;
    }

    // Sort the hand to ensure consecutive cards are adjacent
    std::sort(hand.begin(), hand.end());

    // Iterate through each card in the hand to form groups
    for (int card : hand) {
        // If the current card has already been used up, skip it
        if (count[card] == 0) {
            continue;
        }

        // Attempt to form a group starting from the current card
        for (int i = 0; i < groupSize; ++i) {
            // If the next card in the sequence is not available, return false
            if (count[card + i] <= 0) {
                return false;
            }
            // Decrement the count of the next card in the sequence
            count[card + i]--;
        }
    }

    // If all groups can be formed, return true
    return true;
}

};