class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int, int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }
        auto it = mp.begin();
        while(it!=mp.end()){
            if(it->second==0){
                it++;
                continue;
            }
            int start = it->first;
            int freq = it->second;
            for(int i=0;i<groupSize;i++){
                if(mp[start+i]<freq) return false;
                mp[start+i]-=freq;
            }
            it++;
        }
        return true;
    }
};