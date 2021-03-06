class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        vector<int> balances(20, 0);
        for (const auto& t : transactions) {
            int from = t[0];
            int to = t[1];
            int amount = t[2];
            balances[from] -= amount;
            balances[to] += amount;
        }
        vector<int> debt, credit;
        for (int bal : balances) {
            if (bal < 0) debt.push_back(-bal);
            else if (bal > 0) credit.push_back(bal);
        } 
        min_trans = debt.size() + credit.size();
        solve(debt, credit, 0);
        return min_trans;
    }
    
    void solve(vector<int>& debt, vector<int>& credit, int trans) {
        if (debt.size() == 0 && credit.size() == 0) {
            min_trans = min(min_trans, trans); 
            return;
        }
        if (trans >= min_trans) return;
        unordered_map<int, int> seen;
        for (int i = 0; i < debt.size(); ++i) {
            seen[debt[i]] = i;
        }
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < credit.size(); ++i) {
            if (seen.count(credit[i])) {
                idx1 = seen[credit[i]];
                idx2 = i;
                break;
            }
        }
        if (idx1 != -1) {
            int claimed = debt[idx1];
            swap(debt[idx1], debt.back());
            debt.pop_back();
            swap(credit[idx2], credit.back());
            credit.pop_back();
            solve(debt, credit, trans + 1);
            // Put the values back at their indices.
            debt.push_back(claimed);
            swap(debt[idx1], debt.back());
            credit.push_back(claimed);
            swap(credit[idx2], credit.back());
            return; 
        } 
        for (int i = 0; i < credit.size(); ++i) {
            if (debt.back() < credit[i]) {
                int claimed = debt.back();
                credit[i] -= claimed;
                debt.pop_back();
                solve(debt, credit, trans + 1);
                credit[i] += claimed;
                debt.push_back(claimed);
            } else {
                int claimed = credit[i];
                debt.back() -= claimed;
                swap(credit[i], credit.back());
                credit.pop_back();
                solve(debt, credit, trans + 1);
                debt.back() += claimed;
                credit.push_back(claimed);
                swap(credit[i], credit.back());    
            }
        }
    }
    
    int min_trans;
};