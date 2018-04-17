class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0)
            return ans;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++){
            vector<int> tmp;
            tmp.push_back(candidates[i]);
            DFS(candidates, i, tmp, candidates[i], target);
        }
        return ans;
    }
    
    void DFS(vector<int>& candidates, int pos, vector<int>& tmp, int sum, int target){
        //for (int i = 0; i < tmp.size(); ++i)
        //    cout << tmp[i] << " ";
        //cout << "-> " << sum << endl;
        if (sum == target){
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }
        if (sum > target){
            tmp.pop_back();
            return;
        }
        for (int i = pos; i < candidates.size(); ++i){
            tmp.push_back(candidates[i]);
            DFS(candidates, i, tmp, sum + candidates[i], target);
        } 
        tmp.pop_back();
    }
};