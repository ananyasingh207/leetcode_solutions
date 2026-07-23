class Solution {
public:
    int openLock(vector<string>& deadends, string target){
        if(target=="0000") return 0;
        string start = "0000";
        queue<pair<string, int>> q;
        q.push({start,0});
        unordered_map<string,bool> mp;
        for(int i=0;i<deadends.size();i++){
            mp[deadends[i]]=true;
        }
        if(mp.find("0000")!=mp.end()) return -1;
        unordered_map<string,bool> visited;
        visited["0000"] = true;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            string curr = front.first;
            int moves = front.second;
            for(int i=0;i<curr.size();i++){
                char og  = curr[i];
                char up = (og=='9') ? '0' : og+1;
                curr[i]=up;
                if(curr==target) return moves+1;
                if(!visited[curr] && mp.find(curr)==mp.end()){
                    q.push({curr,moves+1});
                    visited[curr]=true;
                }
                char down = (og=='0') ? '9' : og-1;
                curr[i]=down;
                if(curr==target) return moves+1;
                if(!visited[curr] && mp.find(curr)==mp.end()){
                    q.push({curr,moves+1});
                    visited[curr]=true;
                }
                curr[i]=og;
            }
        }
        return -1;
    }
};