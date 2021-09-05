class Solution {
    public int minSteps(int n) {
        Queue<Node> q = new LinkedList();
        if (n==1) return 0;
        q.add(new Node(2, 1, 2));
        int rec = Integer.MAX_VALUE;
        while(!q.isEmpty()) {
            Node cur = q.poll();
            if (cur.size==n) {
                rec = Math.min(rec, cur.step);
                continue;
            }
            if (cur.size>n) continue;
            q.add(new Node(cur.size+cur.copySize, cur.copySize, cur.step+1));
            q.add(new Node(cur.size+cur.size, cur.size, cur.step+2));
        }
        return rec;
    }
}
class Node {
    int size;
    int copySize;
    int step;
    public Node(int s, int c, int p) {
        size = s;
        copySize = c;
        step = p;
    }
}