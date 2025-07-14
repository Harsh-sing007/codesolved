class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec1[0] < rec2[2] &&  // left of rec1 < right of rec2
               rec1[2] > rec2[0] &&  // right of rec1 > left of rec2
               rec1[1] < rec2[3] &&  // bottom of rec1 < top of rec2
               rec1[3] > rec2[1];    // top of rec1 > bottom of rec2
    
  
    }
}