class MyCalendar {
    
    private SegmentTree tree;

    public MyCalendar() {
        tree = new SegmentTree(0, (int) 1e9);
    }
    
    public boolean book(int start, int end) {
        if(tree.query(start, end)){
            //System.out.print(end);
            //System.out.print(" ");
            return tree.modify(start, end, true);            
        }
        else 
            return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */

class SegmentTreeNode{
    public int start, end;
    public boolean booked;
    public SegmentTreeNode left, right;
    
    public SegmentTreeNode(int start, int end, boolean book){
        this.start = start;
        this.end = end;
        booked = book;
        left = right = null;
    }
}

class SegmentTree{
    private SegmentTreeNode root;
    
    public SegmentTree(int start, int end){
        root = new SegmentTreeNode(start, end, false);
    }
    
    public boolean modify(int start, int end, boolean book){
        return modify(root, start, end, book);
    }
    
    private boolean modify(SegmentTreeNode node, int start, int end, boolean book){
        
        if(node.start == start && node.end == end){
            node.booked = book;
            return node.booked;
        }
        
        if(start >= node.end || end <= node.start) return false;
        
        int mid = node.start + (node.end - node.start) / 2;
        
        if(node.left == null){
            node.left = new SegmentTreeNode(node.start, mid, node.booked);
            node.right = new SegmentTreeNode(mid, node.end, node.booked);
        }

        boolean leftBooked = modify(node.left, start, Math.min(mid, end), book);
        boolean rightBooked = modify(node.right, Math.max(mid, start), end, book);
        
        node.booked = leftBooked || rightBooked;
        
        return leftBooked || rightBooked;
    }
    
    
    public boolean query(int start, int end){
        return query(root, start, end);
    }
    
    private boolean query(SegmentTreeNode node, int start, int end){
        
        if(node.start == start && node.end == end){
            return !node.booked;
        }
        
        if(node.left == null || node.right == null) return !node.booked;
        
        int mid = node.start + (node.end - node.start) / 2;        
        
        if(end <= mid){
            return query(node.left, start, end);
        }
        
        if(start >= mid){
            return query(node.right, start, end);
        }
        
        return query(node.left, start, mid) &
                query(node.right, mid, end);
    }
}