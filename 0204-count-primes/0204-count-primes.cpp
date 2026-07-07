class Solution {
public:
    int countPrimes(int n) {
        if(n<=1){
            return false;
        }
        vector<bool> isPrime(n,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i<sqrt(n);i++){
            if(isPrime[i]){
                for(int j=i*i;j<n;j+=i){
                    isPrime[j]=false;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};