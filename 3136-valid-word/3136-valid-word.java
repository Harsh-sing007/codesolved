class Solution {
    public boolean isValid(String word) {
        if (word == null || word.length() < 3) return false;

        boolean hasVowel = false;
        boolean hasConsonant = false;
        String vowels = "aeiouAEIOU";

        for (char c : word.toCharArray()) {
            if (Character.isLetter(c)) {
                if (vowels.indexOf(c) >= 0) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (Character.isDigit(c)) {
                // digits are allowed
            } else {
                // invalid character found
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
}
