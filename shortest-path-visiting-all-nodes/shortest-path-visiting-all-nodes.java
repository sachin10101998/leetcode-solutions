class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        int fullMask = (1 << n) - 1;
        
        Set<String> visited = new HashSet<>();
        Queue<Node> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            Node node = new Node(i, 1<<i);
            que.offer(node);
            visited.add(node.toString());
        }
        
        int level = 0;
        while (!que.isEmpty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node node = que.poll();
                if (node.mask == fullMask) return level;
                for (int next : graph[node.id]) {
                    Node nextNode = new Node(next, node.mask | (1 << next));
                    if (visited.contains(nextNode.toString())) continue;
                    que.offer(nextNode);
                    visited.add(nextNode.toString());
                }
            }
            level++;
        }
        
        return level;
    }
    
    class Node {
        int id;
        int mask;
        
        Node(int id, int mask){
            this.id = id; this.mask = mask;
        }
        
        public String toString() {
            return id + " " + mask;
        }
    }
}