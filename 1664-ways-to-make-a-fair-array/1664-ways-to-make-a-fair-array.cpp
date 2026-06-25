class Solution {
public:

    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==2){
            return 0;
        }
        vector<int> evenPrefix(n);
        vector<int>oddPrefix(n);
        evenPrefix[0]=nums[0];
        oddPrefix[0]=0;
        for(int i=1;i<n;i++){
            if(i%2==0){
                evenPrefix[i]=evenPrefix[i-1]+nums[i];
                oddPrefix[i]=oddPrefix[i-1];
            }
            else{
                oddPrefix[i]=oddPrefix[i-1]+nums[i];
                evenPrefix[i]=evenPrefix[i-1];
            }
        }
        int count = 0;
        int newEven = 0, newOdd = 0;
        for(int i=0;i<n;i++){
            if(i==0){
                newEven = oddPrefix[n-1];
                newOdd = evenPrefix[n-1]-evenPrefix[0];
            }
            else{
                newEven = evenPrefix[i-1]+(oddPrefix[n-1]-oddPrefix[i]);
                newOdd = oddPrefix[i-1]+(evenPrefix[n-1]-evenPrefix[i]);
            }
            if(newEven == newOdd){
                count++;
            }
        }
        return count;
    }
};