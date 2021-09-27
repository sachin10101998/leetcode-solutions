class SnapshotArray {
public:
    vector<vector<pair<int, int>>> data;
    int snapIdx;
    SnapshotArray(int length) {
        data.resize(length);
        snapIdx = 0;
    }
    
    void set(int index, int val) {
        if (data[index].empty() || data[index].back().first < snapIdx)
            data[index].emplace_back(snapIdx, val);
        else
            data[index].back().second = val;
    }
    
    int snap() {
        return snapIdx++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(data[index].begin(), data[index].end(), make_pair(snap_id, INT_MAX));
        if (it == data[index].begin())  // no data at snap_id
            return 0;
        else    // return the data with snapIdx <= snap_id, which is the prev of upper_bound
            return prev(it)->second;
    }
};
