import java.util.*;

class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        ArrayList<Point> pointList = new ArrayList<>();
        for (int i=0; i<buildings.length;++i){
            pointList.add(new Point(buildings[i][0], buildings[i][2], i, true));
            pointList.add(new Point(buildings[i][1], buildings[i][2], i, false));
        }
        Collections.sort(pointList, new PointComparator());
        HashSet<Integer> rectSet = new HashSet<>();
        TreeMap<Integer, Integer> heightMap= new TreeMap();
        List<Point> result = new ArrayList<>();
        for (int i = 0; i<pointList.size(); ++i){
            Point currentPoint = pointList.get(i);
            if (currentPoint.isStart) {
                rectSet.add(currentPoint.rectIndex);
                addHeightToMap(currentPoint.y, heightMap);
            }
            else {
                rectSet.remove(currentPoint.rectIndex);
                removeHeightFromMap(currentPoint.y, heightMap);
            }
            result.add(new Point(currentPoint.x, getMaxHeight(heightMap)));
        }
        return buildAnswer(result);
    }
}

class PointComparator implements Comparator<Point>{

    @Override
    public int compare(Point o1, Point o2) {
        if (o1.x < o2.x) return -1;
        if (o1.x > o2.x) return 1;
        if (o1.y < o2.y) return -1;
        if (o1.y > o2.y) return 1;
        return 0;
    }
}

class Point{
    int x;
    int y;
    int rectIndex = -1;
    boolean isStart = true;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public Point(int x, int y, int rectIndex, boolean isStart) {
        this.x = x;
        this.y = y;
        this.rectIndex = rectIndex;
        this.isStart = isStart;
    }
}