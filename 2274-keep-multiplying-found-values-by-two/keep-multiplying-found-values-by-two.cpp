class Solution {
public:
    static int findFinalValue(const vector<int>& a, const int k) {
        unsigned int bits = 0;
        for (const int x : a) {
            const auto [q, r] = div(x, k);
            if (r == 0 && popcount((unsigned)q) == 1) {
                bits |= q;
            }
        }
        return k * (1 << countr_one(bits));
    }
};