class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder temp = new StringBuilder("");
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(Character.isLetterOrDigit(ch)){
                ch = Character.toLowerCase(ch);
                temp.append(ch);
            }
        }
        String original = temp.toString();
        temp.reverse();
        String reversed = temp.toString();
        return original.equals(reversed);
    }
}