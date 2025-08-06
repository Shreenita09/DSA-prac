#define ll int
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        ll n = fruits.size();
        ll sq = sqrtl(n);
        //  Set max for each block
        vector<ll> mxblocks(sq + 2);
        for (ll i = 0; i < n; i++) {
            mxblocks[i / sq] = max(mxblocks[i / sq], baskets[i]);
        }
        ll ans = 0;
        for (ll fruit : fruits) {
            ll block = -1;
            //  Check the first block that has the max element >= fruit(can place the fruit at this basket)
            for (ll i = 0; i < sq + 2; i++) {
                if (mxblocks[i] >= fruit) {
                    block = i;
                    break;
                }
            }
            //  Can't place
            if (block == -1) {
                ans++;
                continue;
            }
            //  Find the first element in the block we found that is >= fruit(it is not necessary the max element)
            //  the 'block' with index 'i' is in range [i * sq, (i + 1) * sq] exclusive of 'baskets'
            for (ll i = block * sq; i < min(n, (block + 1) * sq); i++) {
                if (baskets[i] >= fruit) {
                    //  mark as used
                    baskets[i] = 0;
                    break;
                }
            }
            //  Get new max
            mxblocks[block] = 0;
            for (ll i = block * sq; i < min(n, (block + 1) * sq); i++) {
                mxblocks[block] = max(mxblocks[block], baskets[i]);
            }
        }
        return ans;
    }
};