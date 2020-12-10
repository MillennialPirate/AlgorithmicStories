class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //we maintain a stack of pairs 
        stack<pair<int,int>> s;
        vector<pair<int,int>> inter;
        for(int i = 0; i < intervals.size(); i++)
        {
            inter.push_back(make_pair(intervals[i][0],intervals[i][1]));
        }
        sort(inter.begin(),inter.end());
        s.push(make_pair(inter[0].first,inter[0].second));
        for(int i = 1; i < inter.size(); i++)
        {
            if(inter[i].first <= s.top().second)
            {
                if(inter[i].second > s.top().second)
                {
                    s.top().second = inter[i].second;
                }
            }
            else
            {
                s.push(make_pair(inter[i].first,inter[i].second));
            }
        }
        vector<pair<int,int>> res;
        while(!s.empty())
        {
            res.push_back(make_pair(s.top().first,s.top().second));
            s.pop();
        }
        vector<vector<int>> res1;
        for(int i = 0; i < res.size(); i++)
        {
            vector<int> x;
            x.push_back(res[i].first);
            x.push_back(res[i].second);
            res1.push_back(x);
            x.clear();
        }
        return res1;
    }
};
