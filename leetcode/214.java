class Solution {
    public String shortestPalindrome(String s) {
        Manacher manacher = new Manacher(s);
        int[] span = manacher.getSpan();
        int r = 0;
        int c = 0;
        for (int i=1;i<span.length-1;++i)
            if (i - span[i] == 1) {
                if (r < i + span[i]) {
                    r = i + span[i];
                    c = i;
                }
            }
        String palindromePrefix = manacher.getPalindrome(c);
        StringBuilder sb = new StringBuilder();
        for (int i=0; i<s.length()- palindromePrefix.length(); ++i){
            sb.append(s.charAt(s.length()-1-i));
        }
        sb.append(s);
        return sb.toString();
    }
}

public class Manacher {

    private int [] a;
    private int [] span;

    Manacher(String originalSt){
        a = new int[originalSt.length() * 2 + 3];
        span = new int[originalSt.length() * 2 + 3];
        for (int i=0; i<span.length;++i) span[i] = 0;
        a[0] = -2;
        for (int i = 0; i<originalSt.length(); ++i){
            a[i*2 + 1] = -1;
            a[i*2 + 2] = originalSt.charAt(i);
        }
        a[originalSt.length() * 2 + 1] = -1;
        a[originalSt.length() * 2 + 2] = -3;

        int c = 0;
        int r = 0;
        for (int i=1; i<a.length-1; ++i){
            int iMirror = 2*c - i;
            if (r > i) span[i] = Math.min(r - i, span[iMirror]);
            while (a[ i-span[i]-1 ] == a[ i+span[i]+1 ]) ++span[i];
            if (i + span[i] > r){
                r = i + span[i];
                c = i;
            }
        }
    }

    private Character convertIntegerBackToChar(int x){
        if (x == -1) return '#';
        if (x == -2) return '^';
        if (x == -3) return '$';
        return (char) x;
    }

    public String getPaddedString(){
        StringBuilder sb = new StringBuilder();
        for (int i=0;i<a.length;++i) sb.append(convertIntegerBackToChar(a[i]));
        return sb.toString();
    }

    public int[] getPaddedArray(){
        return a;
    }

    public int[] getSpan(){
        return span;
    }

    public int getLongestPalindromeLength(){
        int len = 0;
        for (int i=1; i<span.length; ++i)
            if (span[i] > len) len = span[i];
        return len;
    }

    public List getLongestPalindromeLocation(){
        int maxLen = getLongestPalindromeLength();
        List list = new ArrayList<Integer>();
        for (int i=0;i<span.length;++i)
            if (span[i] == maxLen) list.add(i);
        return list;
    }

    public String getPalindrome(Integer loc){
        return getPalindrome(loc, span[loc]);
    }

    public String getPalindrome(int loc, int length){
        StringBuilder sb = new StringBuilder();
        for (int i=loc - length; i<=loc+length;++i)
            if (a[i] > 0) sb.append((char)a[i]);
        return sb.toString();
    }

}
