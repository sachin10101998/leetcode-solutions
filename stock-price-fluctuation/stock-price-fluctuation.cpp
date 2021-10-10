class StockPrice {
public:
    unordered_map<int,int> mp;
    multiset<pair<int,int>> pq,st;
    vector<int> v;
    int size;
    StockPrice() {
        size=0;
    }
    
    void update(int timestamp, int price) {
        multiset<pair<int,int>> :: iterator it;
        
        if(mp.find(timestamp)==mp.end())
        {
            st.insert({timestamp,price});
            mp.insert({timestamp,price});
            pq.insert({price,timestamp});
        }
        else
        {       
            int prev=mp[timestamp];
            it=pq.find({prev,timestamp});
            pq.erase(it);
            pq.insert({price,timestamp});
            mp[timestamp]=price;
            it=st.find({timestamp,prev});
            st.erase(it);
            st.insert({timestamp,price});
        }

    }
    
    int current() {
        multiset<pair<int,int>> :: iterator it;
        it=st.end();
        it--;
        pair<int,int> ans=(*it);
        cout << ans.first << ans.second;
        return ans.second;
    }
    
    int maximum() {
        multiset<pair<int,int>> :: iterator it;
        it=pq.end();
        it--;
        pair<int,int> ans=(*it);
        return ans.first;
    }
    
    int minimum() {
        multiset<pair<int,int>> :: iterator it;
        it=pq.begin();
        pair<int,int> ans=(*it);
        return ans.first;
    }
};