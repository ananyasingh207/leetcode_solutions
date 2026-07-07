class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int j = 0;
        int maxFruits = 0;
        unordered_map<int, int> basket;
        for (int i = 0; i < n; i++) {
            basket[fruits[i]]++;
            while (basket.size() > 2) {
                basket[fruits[j]]--;
                if (basket[fruits[j]] == 0) {
                    basket.erase(fruits[j]);
                }
                j++;
            }
            maxFruits = max(maxFruits, i - j + 1);
        }
        return maxFruits;
    }
};