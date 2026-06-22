class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool> illuminated(n,false);
        int leftReached = 0;
        for(int i=0;i<n;i++){
            if(lights[i]!=0){
                int l = max(0,i-lights[i]);
                int r = min(n-1,i+lights[i]);
                int left_boundary = (l<leftReached && !illuminated[l]) ? l : max(l,leftReached);
                for(int j=left_boundary;j<=r;j++){
                    illuminated[j]=true;
                }
                leftReached = max(leftReached,r+1);
            }
        }
        int pos = 0;
        int bulbs = 0;
        while(pos<n){
            if(!illuminated[pos]){
                bulbs++;
                int nextPos =  min(n-1,pos+2)-max(0,pos) + 1;
                pos+=nextPos;
            }
            else{
                pos++;
            }
        }
        return bulbs;
    }
};