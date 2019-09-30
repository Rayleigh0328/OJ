class Solution {
        private int retrieveFirst(TreeMap<Integer, Integer> m){
        int x = m.firstKey();
        int cnt = m.firstEntry().getValue();
        if (--cnt == 0) m.remove(x);
        else m.replace(x, cnt);
        return x;
    }

    private void insert(TreeMap<Integer, Integer> m, Integer x){
        if (!m.containsKey(x)) m.put(x, 1);
        else m.put(x, m.get(x) + 1);
    }

    public int lastStoneWeight(int[] stones) {
        TreeMap<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());
        for (int x : stones)
            insert(map, x);

        while (map.size()>=2 || (!map.isEmpty() && map.firstEntry().getValue() >=2) ) {
            int x = retrieveFirst(map);
            int y = retrieveFirst(map);
            if (x - y > 0) insert(map, x-y);
        }

        if (map.isEmpty()) return 0;
        else return map.firstKey();
    }
}
