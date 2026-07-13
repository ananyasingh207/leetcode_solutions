class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int intervals = 0;
        vector<int> freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            pq.push(freq[i]);
        }
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;
            while(!q.empty() && q.front().second <= time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int task = pq.top()-1;
                pq.pop();
                if(task>0){
                    q.push({task,time+n+1});
                }
            }
        }
        return time;
    }
};