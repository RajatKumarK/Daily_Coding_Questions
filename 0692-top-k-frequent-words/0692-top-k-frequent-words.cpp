class Solution {
public:
    struct Comparator
    {
        bool operator()(const pair<string,int>& lhs,
                         const pair<string,int>& rhs){
          if (lhs.second == rhs.second)
            return lhs.first > rhs.first;
          else
            return lhs.second < rhs.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        vector<string> res;
        int n = words.size();
        for(int i=0;i<n;i++)
            mp[words[i]]++;
        priority_queue<pair<string,int>,vector<pair<string,int>>,Comparator> pq;
        
        for(auto &x: mp){
            pq.push({x.first,x.second});
        }
        for(int i=0;i<k;i++){
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};