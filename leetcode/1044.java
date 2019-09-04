class Solution {
    public String longestDupSubstring(String st) {
        SuffixArray suffixArray = new SuffixArray(st, new SuffixArrayDoublingConstructor());
        int[] sa = suffixArray.getSa();
        int[] height = suffixArray.getHeight();
        int maxIndex = 0;
        for (int i=1;i<height.length;++i) if (height[maxIndex] < height[i]) maxIndex = i;
        if (height[maxIndex] == 0) return "";
        StringBuilder sb = new StringBuilder();
        for (int i=sa[maxIndex]; i<sa[maxIndex]+height[maxIndex];++i)
            sb.append(st.charAt(i));
        return sb.toString();
    }
    
    public interface SuffixArrayConstructor{
        int[] buildRank(int[] paddedArray);
        int[] buildSaFromRank(int[] rank);
    }
    
    public class SuffixArrayDoublingConstructor implements SuffixArrayConstructor{

        @Override
        public int[] buildRank(int[] a) {
            assert a[a.length - 1] == -1;
            int base = a.length;
            // create rank of length 1
            Map<Long, Integer> rankMap = new TreeMap<>();
            for (int i=0; i<base;++i) rankMap.put(0l + a[i], 0);
            int count = 0;
            for (Long x : rankMap.keySet()) rankMap.put(x, count++);
            int [] rank = new int [base];
            for (int i=0;i<base;++i) rank[i] = rankMap.get(0l + a[i]);
            // loop from length 2^1, 2^2...
            for (int len=1; len<base; len *=2){
                rankMap.clear();
                for (int l = 0; l < base; ++l) rankMap.put(getCombinedRank(rank, len, l), 0);
                count = 0;
                for (Long x : rankMap.keySet()) rankMap.put(x, count++);
                for (int l=0;l<base;++l) rank[l] = rankMap.get(getCombinedRank(rank,len,l));
                if (rankMap.keySet().size() == base) break;
            }

            return rank;
        }

        private long getCombinedRank(int[] array, int dist, int left){
            int right = left + dist;
            long x = new Long(array[left]);
            long y = new Long(right < array.length ? array[right]:0);
            if (right >= array.length) return x * array.length;
            else return x * array.length + y;
        }
        
        @Override
        public int[] buildSaFromRank(int[] rank) {
            int[] sa = new int [rank.length];
            for (int i=0; i<rank.length; ++i) sa[rank[i]] = i;
            return sa;
        }
    }
    
    public class SuffixArray {

    // EOS is the character padded at the end of the original string
    private static final int EOS = -1;

    private int [] a;
    private int [] sa;
    private int [] rank;
    private int [] height;

    public SuffixArray(String st, SuffixArrayConstructor saConstructor){
        a = new int[st.length() + 1];
        for (int i=0; i<st.length();++i) a[i] = st.charAt(i);
        a[st.length()] = -1;

        rank = saConstructor.buildRank(a);
        sa = saConstructor.buildSaFromRank(rank);
        buildHeight();
    }

    private void buildHeight(){
        int currentHeight = 0;
        height = new int [sa.length];
        height[0] = 0;
        for (int i=0;i<sa.length-1; ++i){
            int prevIndex = sa[rank[i] - 1];
            while (a[i + currentHeight] == a[prevIndex + currentHeight]) ++currentHeight;
            height[rank[i]] = currentHeight;
            currentHeight = Math.max(0, currentHeight - 1);
        }
    }

    public int[] getA() {
        return a;
    }

    public int[] getSa() {
        return sa;
    }

    public int[] getRank() {
        return rank;
    }

    public int[] getHeight() {
        return height;
    }

    

    
}
}
