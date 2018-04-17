class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> times;
        
        for(int i = 0; i < 12; i++){
            bitset<4> h((size_t) i);
            for(int j = 0; j < 60; j++){
                bitset<6> m((size_t) j);
                if(h.count() + m.count() == num)
                    times.push_back(to_string(i) + (j < 10? ":0": ":") + to_string(j));
            }
        }
        
        return times;
    }
};