class Solution {
    //bfs, dijkstra
    int[] dx = {-1,1,0,0};
    int[] dy = {0,0,-1,1};
    public int minimumEffortPath(int[][] heights) {
        
        boolean[][] v= new boolean[heights.length][heights[0].length];
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() { 
            @Override public int compare(int[] s1, int[] s2) {
                return s1[2]-s2[2];
            }
        });

        //start point
        pq.offer(new int[]{0,0,0});
        v[0][0]=true;
        
        int maxEffort = -1;
        while(!pq.isEmpty()) {
            int[] s = pq.poll();
            int x = s[0];
            int y = s[1];
            v[x][y]=true;
            
            int effort = s[2];
            maxEffort = Math.max(effort,maxEffort);
            if(x==heights.length-1 && y==heights[0].length-1) 
                return maxEffort;
            for(int d=0;d<4;d++) {
                    int x_n = x+dx[d];
                    int y_n = y+dy[d];
             
                    if(0<=x_n && x_n<heights.length && 0<=y_n && y_n<heights[0].length && v[x_n][y_n]==false) { //canMove?
                        int e_n = Math.abs(heights[x_n][y_n] - heights[x][y]);
                        pq.add(new int[]{x_n,y_n,e_n});
                    }
            }
            
        }
                   
        return 0; //dummy return
    }
                   
}