class Solution {
    private static final int INF = 1000000;

    public int maximumSum(int[] arr) {
        if (allNegative(arr)) return getMax(arr);
        return solve(arr, 0, arr.length);
    }

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

    private int solve(int[] arr, int left, int right) {
        if (left == right) return -INF;
        if (left == right - 1) return arr[left];
        int mid = (left + right) / 2;
        int result = Math.max(solve(arr, left, mid), solve(arr, mid, right));

        // left without remove
        int best1 = -INF;
        int currentSum = 0;
        for (int i=mid-1; i>=left; --i){
            currentSum += arr[i];
            if (currentSum > best1) best1 = currentSum;
        }
        // left with remove
        int best2=-INF;
        int currentMin=arr[mid-1];
        currentSum=0;
        for (int i=mid-2; i>=left; --i){
            currentSum += arr[i];
            if (arr[i] < currentMin) {
                currentSum += currentMin;
                currentSum -= arr[i];
                currentMin = arr[i];
            }
            if (currentSum > best2) best2 = currentSum;
        }
        // right without remove
        int best3 = -INF;
        currentSum = 0;
        for (int i=mid; i<right; ++i){
            currentSum += arr[i];
            if (currentSum > best3) best3 = currentSum;
        }
        // right with remove
        int best4 = -INF;
        currentMin = arr[mid];
        currentSum = 0;
        for (int i=mid+1; i<right;++i){
            currentSum += arr[i];
             if (arr[i] < currentMin) {
                currentSum += currentMin;
                currentSum -= arr[i];
                currentMin = arr[i];
             }
             if (currentSum > best4) best4 = currentSum;
        }
        result = Math.max(result, best1 + best3);
        result = Math.max(result, best1 + best4); 
        result = Math.max(result, best2 + best3);
        return result;
    }

}
