class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> que = new PriorityQueue<>(10, Collections.reverseOrder());
        for (int x : stones) que.add(x);
        int x, y;
        while (que.size() >= 2) {
            x = que.poll();
            y = que.poll();
            if (x - y > 0) que.add(x-y);
        }
        if (que.isEmpty()) return 0;
        else return que.poll();
    }
}
