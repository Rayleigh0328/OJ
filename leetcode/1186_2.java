
class Solution {
    private final int INF = 1000000000;

    private boolean allNegative(int[] arr){
        for (int i=0; i<arr.length; ++i)
            if (arr[i] > 0) return false;
        return true;
    }

    private int getMax(int[] arr){
        int result = -INF;
        for (int i=0;i<arr.length;++i)
            if (result < arr[i]) result = arr[i];
        return result;
    }
    
    public int maximumSum(int[] arr) {

        if (allNegative(arr)) return getMax(arr);
        // left[i] means max sum of substrings ends with i
        int[] left = new int[arr.length];
        left[0] = arr[0];
        for (int i=1;i<arr.length;++i)
            left[i] = Math.max(left[i-1] + arr[i], arr[i]);

        // right[i] means max sum of substrings starts with i
        int[] right= new int[arr.length];
        right[arr.length - 1] = arr[arr.length - 1];
        for (int i=arr.length - 2; i>=0; --i)
            right[i] = Math.max(right[i+1] + arr[i], arr[i]);

        int ans = -INF;
        for (int i=0;i<arr.length;++i){
            ans = Math.max(ans, Math.max(left[i] + right[i] - arr[i], left[i] + right[i] - 2*arr[i]));
        }
        return ans;
    }
}

