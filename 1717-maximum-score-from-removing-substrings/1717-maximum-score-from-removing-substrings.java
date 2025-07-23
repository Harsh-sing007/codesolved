public class Solution {
    public int maximumGain(String s, int x, int y) {
        if (x > y) {
            return calculateScore(s, "a", "b", x, y);
        } else {
            return calculateScore(s, "b", "a", y, x);
        }
    }

    private int calculateScore(String s, String firstChar, String secondChar, int firstScore, int secondScore) {
        Stack<Character> stack1 = new Stack<>();
        int score = 0;

        // First pass: remove high priority pair (like "ab" or "ba")
        for (char c : s.toCharArray()) {
            if (!stack1.isEmpty() && stack1.peek() == firstChar.charAt(0) && c == secondChar.charAt(0)) {
                stack1.pop();
                score += firstScore;
            } else {
                stack1.push(c);
            }
        }

        // Second pass: remove remaining lower priority pair
        Stack<Character> stack2 = new Stack<>();
        while (!stack1.isEmpty()) {
            char c = stack1.pop();
            if (!stack2.isEmpty() && c == secondChar.charAt(0) && stack2.peek() == firstChar.charAt(0)) {
                stack2.pop();
                score += secondScore;
            } else {
                stack2.push(c);
            }
        }
         return score;

       
    }
}
