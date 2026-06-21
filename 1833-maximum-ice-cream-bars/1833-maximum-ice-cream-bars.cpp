class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int icecream = 0;
        for(int i=0;i<n;i++){
            coins = coins-costs[i];
            if(coins<0){
                break;
            }
            if(coins==0){
                icecream++;
                break;
            }
            icecream++;
        }
        return icecream;
    }
};