class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>um;
        //Use unordered map and key as the sorted string
        for (auto& s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            um[t].push_back(s);
        }
        
        for (auto& it : um) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};