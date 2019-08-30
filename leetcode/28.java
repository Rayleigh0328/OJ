class Solution {
    public int strStr(String haystack, String needle) {
        if (needle.length() == 0) return 0;
        Kmp kmp = new Kmp(haystack, needle);
        List<Integer> list = kmp.getMatchPoint();
        if (list.isEmpty()) return -1;
        else return list.get(0);
    }
    
    public class Kmp {

    private int[] s;
    private int[] p;
    private int[] t;
    private int[] a;

    public Kmp(String string, String pattern){
        int i,j;
        // pad arrays
        s = convertString(string, -1);
        p = convertString(pattern, -2);

        // construct function phi
        t = new int [p.length];
        for (i=0;i<p.length;++i) t[i] = -1;
        i=1; j=0;
        while (i < t.length){
            if (t[i] == -1) t[i] = j;
            if (j < 0) {++i; j=0;}
            else if (p[i] == p[j]) {++i; ++j;}
            else {j = t[j];}
        }
        // optimize t, the following loop can be commented out
       for (i=1;i<t.length;++i)
           if (t[i] >= 0 && p[i] == p[t[i]]) t[i] = t[t[i]];
           else t[i] = t[i];

        // matching, store result in a
        a = new int [s.length];
        for (i=0; i<a.length;++i) a[i] = -1;
        i = 0; j = 0;
        while (i < a.length){
            if (a[i] == -1) a[i]=j;
            if (j < 0) {++i; j=0;}
            else if (s[i] == p[j])  {++i; ++j;}
            else {j = t[j];}
        }
    }

    private int[] convertString(String string, int endSymbol){
        int[] result = new int[string.length() + 1];
        for (int i=0;i<string.length();++i) result[i] = string.charAt(i);
        result[string.length()] = endSymbol;
        return result;
    }

    public int[] getMatchResult(){
        return a;
    }

    public List<Integer> getMatchPoint(){
        List<Integer> result = new ArrayList<>();
        for (int i=0;i<a.length;++i)
            if (a[i] == p.length - 1) result.add(i-p.length+1);
        return result;
    }
}
}
