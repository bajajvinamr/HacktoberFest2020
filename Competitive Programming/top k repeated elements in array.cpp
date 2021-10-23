class Solution {
 public:
     vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int,int> mp;vector<int>v;
         for(auto &x: nums)
             mp[x]++;
         priority_queue<pair<int,int>> pq;

         for(auto &x: mp)
             pq.push({x.second, x.first});


         int a=k;
         while(k--)
         {
              v.push_back(pq.top().second);
             pq.pop();
         }

         return v;
     }
 };
