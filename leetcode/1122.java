class Solution {
    
    class MyIntComparator implements Comparator{
        HashMap<Integer, Integer> pos;

        MyIntComparator(HashMap<Integer, Integer> map){
            pos = map;
        }

       int compareInt(int x, int y){
           if (x < y) return -1;
           else if (x == y) return 0;
           return 1;
       }
        
        @Override
        public int compare(Object o1, Object o2) {
            Integer x = (Integer) o1;
            Integer y = (Integer) o2;
            if (pos.containsKey(x) && pos.containsKey(y)) return compareInt(pos.get(x),pos.get(y));
            if (!pos.containsKey(x) && !pos.containsKey(y)) return compareInt(x, y);
            if (pos.containsKey(x)) return -1;
            else return 1;
        }
    }

    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<arr2.length; ++i) map.put(arr2[i],i);
        ArrayList<Integer> list1 = new ArrayList();
        for (int x : arr1) list1.add(x);
        Collections.sort(list1, new MyIntComparator(map));
        int result [] = new int [list1.size()];
        for (int i=0;i<list1.size();++i)
            result[i] = list1.get(i);
        return result;
    }
    
}
