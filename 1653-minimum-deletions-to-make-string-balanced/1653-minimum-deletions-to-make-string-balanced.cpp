class Solution {
public:
    int minimumDeletions(string s) {
        int b = 0, del = 0;

        for (char c : s) {
            if (c == 'b') {
                b++;
            } else {
                del = min(del + 1, b);
            }
        }

        return del;
    }
};
