class Solution {
    public int largestRectangleArea(int[] heights) {
        HistogramLargestRectangle solver = new HistogramLargestRectangle(
               heights
        );
        return solver.getMaxArea();
    }
    
    public class HistogramLargestRectangle {

    private int[] height;
    private int[] area;
    private int span;

    public HistogramLargestRectangle(int[] input){

        // construct array height
        span = input.length;
        height = new int [span + 2];
        height[0] = height[span + 1] = -1;
        for (int i=0;i<span;++i) height[i+1] = input[i];

        // construct array area
        area = new int [span + 2];
        area[0] = area[span+1] = 0;
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        for (int i=1;i<area.length;++i){
            int m=stack.peek();
            while (height[m] > height[i]){
                stack.pop();
                int l= stack.peek();
                area[m] = (i - l - 1) * height[m];
                m = stack.peek();
            }
            stack.push(i);
        }
    }

    public int getMaxAreaPos(){
        int result = 0;
        for (int i=1; i<area.length; ++i) if (area[i] > area[result]) result = i;
        return result;
    }

    public int getMaxArea(){
        return area[getMaxAreaPos()];
    }

    public int[] getHeight() {
        return height;
    }

    public int[] getArea(){
        return area;
    }
}
}
