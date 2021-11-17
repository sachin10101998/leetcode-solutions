class Solution {
    vector<pair<int, int>> resort;
    
    priority_queue<int, vector<int>, greater<int>> nums[10];
    int used[30001];
    int n;
    int getSum(int index)  {
        int sum = 0;
        while (index > 0) { 
            sum += used[index];
            index -= index & (-index); 
        } 
        return sum; 
    } 
    
    void updateBIT(int index, int val) 
    { 
        while (index <= n) 
        { 
        used[index] += val;
        index += index & (-index); 
        } 
    }
    
public:
    string minInteger(string num, int k) {
        memset(used, 0, sizeof(used));
        
        int ctr = 0;
        n = num.size();
        for (int i = 0; i < n; i++) {
            nums[num[i] - '0'].push(i + 1);
        }
        string res;
        while (ctr < n && k > 0) {
            for (int i = 0; i <= 9; i++) {
                if (!nums[i].empty()) {
                    int cur = nums[i].top();
                    
                    int holes = getSum(cur - 1);
                    int act = cur - holes;
                    if (act - 1 <= k) {
                        res += ('0' + i);
                        k -= (act - 1);
                        updateBIT(cur, 1);
                        nums[i].pop();
                        break;
                    }
                }
            }
            ctr++;
        }
        
        for(int i = 0; i <= 9; i++) {
            while (!nums[i].empty()) {
                resort.emplace_back(nums[i].top(), i);
                nums[i].pop();
            }
        }
        
        sort(resort.begin(), resort.end());
        for (auto &p : resort) {
            res += ('0' + p.second);
        }
        return res;
    }
};