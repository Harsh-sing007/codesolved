class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        long maxArea = 0;
        int n = bottomLeft.length;
        for (int i = 0; i < n; i++) {
            int ax1 = bottomLeft[i][0], ay1 = bottomLeft[i][1];
            int ax2 = topRight[i][0], ay2 = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int bx1 = bottomLeft[j][0], by1 = bottomLeft[j][1];
                int bx2 = topRight[j][0], by2 = topRight[j][1];
                
                int overlapWidth = Math.min(ax2, bx2) - Math.max(ax1, bx1);
                int overlapHeight = Math.min(ay2, by2) - Math.max(ay1, by1);
                
                int side = Math.min(overlapWidth, overlapHeight);
                if (side > 0) {
                    maxArea = Math.max(maxArea, 1L * side * side);
                }
            }
        }
        return maxArea;
    }
}
