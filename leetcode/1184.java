class Solution {
    public int distanceBetweenBusStops(int[] distance, int start, int destination) {
        if (start == destination) return 0;
        if (start > destination){
            // make sure start < destination
            int tmp = start;
            start = destination;
            destination = tmp;
        }
        int totalSum = 0;
        for (int i=0; i<distance.length;++i) totalSum += distance[i];
        int dist = 0;
        for (int i=start; i<destination;++i) dist += distance[i];
        return Math.min(dist, totalSum - dist);
    }
}
