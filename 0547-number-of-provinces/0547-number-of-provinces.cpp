class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int num){
        if(parent[num]==num){
            return num;
        }
        return parent[num] = find(parent[num]);
    }

    void unionSet(int& a, int& b){
        int parA = find(a);
        int parB = find(b);
        if(parA==parB) return;
        if(rank[parA]==rank[parB]){
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA]>rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parA] = parB;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int provinces = n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    if(find(i)==find(j)) continue;
                    else{
                        unionSet(i,j);
                        provinces--;
                    }
                }
            }
        }
        return provinces;
    }
};