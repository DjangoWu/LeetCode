class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> counts{0};
        
        for(int i = 1; i < num+1; i++)
            counts.push_back(counts[i/2] + i%2);
        
        return counts;
    }
};