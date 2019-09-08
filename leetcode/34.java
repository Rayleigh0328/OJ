class Solution {
    public int[] searchRange(int[] arr, int target) {
        int[] result = new int[2];
        result[0]=lb(arr, target, 0, arr.length);
        result[1]=rb(arr, target, 0, arr.length);
        return result;
    }

    private int lb(int[] arr, int target, int left, int right){
        // empty
        if (left >= right) return -1;
        // 1 element
        if (left == right - 1)
            if (arr[left] == target) return left;
            else return -1;
        // 2 elements
        if (left == right - 2)
            if (arr[left] == target) return left;
            else if (arr[left+1] == target) return left+1;
            else return -1;

        // more than 3
        int mid = (left + right)/2;
        if (arr[mid] == target) return lb(arr, target, left, mid+1);
        else if (arr[mid] < target) return lb(arr,target,mid+1, right);
        else return lb(arr,target,left,mid);
    }


    private int rb(int[] arr, int target, int left, int right){
        // empty
        if (left >= right) return -1;
        // 1 element
        if (left == right - 1)
            if (arr[left] == target) return left;
            else return -1;
        // 2 elements
        if (left == right - 2)
            if (arr[left+1] == target) return left+1;
            else if (arr[left] == target) return left;
            else return -1;

        // more than 3
        int mid = (left + right)/2;
        if (arr[mid] == target) return rb(arr, target, mid, right);
        else if (arr[mid] < target) return rb(arr,target,mid+1, right);
        else return rb(arr,target,left,mid);
    }
}

