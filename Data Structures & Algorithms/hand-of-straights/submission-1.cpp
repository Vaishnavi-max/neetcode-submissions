class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }

        unordered_map<int, int> freq;
        sort(hand.begin(), hand.end());
        int minm = hand[0], maxm = hand[n - 1];

        for (int i = 0; i < n; i++) {
            freq[hand[i]]++;
        }

        int x = minm;
        while (x <= maxm) {
            if (freq[x] == 0) {
                x++;
                continue;
            }

            // Always attempt to form a group starting at the current smallest available card 'x'
            for (int i = x; i < x + groupSize; i++) {
                if (!freq.count(i) || freq[i] == 0) {
                    return false;
                }
                freq[i]--;
            }
            // Do NOT increment x here so that if freq[x] > 0 remains, it forms another group starting at x again
        }

        return true;
    }
};