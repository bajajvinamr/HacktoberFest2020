class Solution {
  public:
    vector<int> changeBits(int N) {
        // code here
        vector<int>ans;
        int num=N;
        int sum=0;
        int i=0;
        if(N==0){
            ans.push_back(1);
            ans.push_back(1);
        }
        while(num>0){
            sum+=pow(2,i);
            num/=2;
            i++;
        }
        ans.push_back(sum-N);
        ans.push_back(sum);
        return ans;
    }
};
