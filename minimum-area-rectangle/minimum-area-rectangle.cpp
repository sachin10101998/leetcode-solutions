class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        map <pair<int, int>, int> m;
        int n = points.size();
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            m[{points[i][0], points[i][1]}]++;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int x1, y1, x2, y2;
                x1 = points[i][0];
                y1 = points[j][1];
                if(m.find({x1, y1}) != m.end())
                {
                    x2 = points[j][0];
                    y2 = points[i][1];
                    if(m.find({x2, y2}) != m.end())
                    {
                        if(x1 != x2 && y1 != y2)
                            mini = min(abs(x1 - x2)*abs(y1 - y2), mini);
                    }
                }
            }
        }
        
        if(mini == INT_MAX)
            return 0;
        
        return mini;
    }
};