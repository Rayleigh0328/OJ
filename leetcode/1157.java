class MajorityChecker {

    int[] arr;
    
    public MajorityChecker(int[] arr) {
        this.arr = arr;
    }
    
    public int query(int left, int right, int threshold) {
        int m = -1;
        int count = 0;
        for (int i=left; i<=right; ++i)
            if (count == 0) {m = arr[i]; count=1;}
            else if (arr[i] == m) {++count;}
            else {--count;}
        return (checkMajority(m,left,right,threshold)?m:-1);
    }
    
    private boolean checkMajority(int candidate, int left, int right, int threshold){
        int count = 0;
        for (int i=left; i<=right; ++i) 
            if (arr[i] == candidate) ++count;
        return (count >= threshold);
    }
}

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker obj = new MajorityChecker(arr);
 * int param_1 = obj.query(left,right,threshold);
 */