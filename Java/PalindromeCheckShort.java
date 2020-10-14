public class PalindromeCheckShort {
    public static void main(String[] args) {
        System.out.println(isPalindrome("seven"));
        System.out.println(isPalindrome("12"));
        System.out.println(isPalindrome("mom"));
        System.out.println(isPalindrome("123321"));
    }
    
    private static boolean isPalindrome(String s) {
        if (s.equals(new StringBuffer(s).reverse().toString()))
            return true;
        else
            return false;
    }
}
