class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};