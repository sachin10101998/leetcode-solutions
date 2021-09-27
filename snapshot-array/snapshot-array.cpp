class SnapshotArray {    
public:
    vector<vector<pair<int, int>>> snapShot;
    int snapId;
    SnapshotArray(int length) {
        vector<vector<pair<int, int>>> x(length, vector<pair<int, int>>());
        this->snapShot = x;
        this->snapId = -1;
    }
    
    void set(int index, int val) {
        if (!snapShot[index].empty() && snapShot[index].back().first == snapId + 1) {
            snapShot[index].back().second = val;
            return;
        }
        
        snapShot[index].push_back(make_pair(snapId + 1, val));
    }
    
    int snap() {
        snapId = snapId + 1;
        return snapId;
    }
    
    int get(int index, int snap_id) {
        if (snap_id > this->snapId) {
            return -1;
        }
        
        if (snapShot[index].empty()) {
            return 0;
        }        
       
        if (snap_id > snapShot[index].back().first) {
            return snapShot[index].back().second;
        }
        
        int idx = lower_bound(snapShot[index].begin(), snapShot[index].end(), make_pair(snap_id, -1)) - snapShot[index].begin();
        idx += snapShot[index][idx].first == snap_id ? 0 : -1;
        return idx < 0 ? 0 : snapShot[index][idx].second;
    }
};