class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        int rows = binaryMatrix.dimensions().get(0);
        int cols = binaryMatrix.dimensions().get(1);
        int smallestIndex = cols;
        for (int row = 0; row < rows; row++) {
            // Binary Search for the first 1 in the row.
            int lo = 0;
            int hi = cols - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (binaryMatrix.get(row, mid) == 0) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            // If the last element in the search space is a 1, then this row
            // contained a 1.
            if (binaryMatrix.get(row, lo) == 1) {
                smallestIndex = Math.min(smallestIndex, lo);
            }
        }
        // If smallest_index is still set to cols, then there were no 1's in 
        // the grid. 
        return smallestIndex == cols ? -1 : smallestIndex;
    }
}