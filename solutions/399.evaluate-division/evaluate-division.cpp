class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> hash;
        for(int i = 0; i < equations.size(); i++){
            hash[equations[i].first][equations[i].second] = values[i];
            hash[equations[i].second][equations[i].first] = 1/values[i];
        }
        
        for(auto val : hash){
            hash[val.first][val.first] = 1;
        }
        for(auto val1 : hash){
            for(auto val2 : hash){
                for(auto val3 : hash){
                    if(hash[val1.first].count(val3.first) && hash[val2.first].count(val1.first))
                        hash[val2.first][val3.first] = hash[val2.first][val1.first] * hash[val1.first][val3.first];
                }
            }
        }
        vector<double> ans;
        for(auto val : queries)
            ans.push_back(hash[val.first].count(val.second)?hash[val.first][val.second]:-1);
        return ans;
    }
};