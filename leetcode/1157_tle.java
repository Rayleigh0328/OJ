class MajorityChecker {

    int[] arr;
    
    public MajorityChecker(int[] arr) {
        this.arr = arr;
    }
    
    public int query(int left, int right, int threshold) {
        ArrayList<Integer> list = new ArrayList();
        for (int i=left; i<=right; ++i) list.add(arr[i]);
        ArrayList<Integer> result = eliminate(list);
        
        for (int i=0; i< result.size(); ++i) 
            if (checkMajority(result.get(i), left, right, threshold)) return result.get(i);

        return -1;
    }
    
    private ArrayList<Integer> eliminate(ArrayList<Integer> list){
        if (list.size() <= 2) return list;
        ArrayList<Integer> result = new ArrayList();
        for (int i=0; i<list.size(); i+=2)
            if (i+1 == list.size() || list.get(i).equals(list.get(i+1))) result.add(list.get(i));
        return eliminate(result);
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