class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> mp;
        for(int i=0;i<wordList.size();i++){
            mp[wordList[i]]=true;
        }
        if(mp.find(endWord)==mp.end()){
            return 0;
        }
        unordered_map<string,bool> visited;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited[beginWord] = true;
        while(!q.empty()){
            auto front = q.front();
            string start = front.first;
            int steps = front.second;
            q.pop();
            for(int i=0;i<start.size();i++){
                char og = start[i];
                for(char ch='a';ch<='z';ch++){
                    if(ch==og) continue;
                    start[i]=ch;
                    if(start==endWord) return steps+1;
                    if(mp.find(start)!=mp.end() && !visited[start]){
                        visited[start]=true;
                        q.push({start,steps+1});
                    }
                }
                start[i] = og;
            }
        }
        return 0;
    }
};