class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        
        int line[] = new int[matrix[0].length];
        for (int i=0;i<line.length;++i) line[i] = 0;
        
        int result = 0;
        for (int i=0; i< matrix.length; ++i){
            // update line
            for (int j=0;j<matrix[i].length;++j)
                line[j] = ((matrix[i][j]=='0')?0:line[j] + 1);
            HistogramLargestRectangle solver = new HistogramLargestRectangle(line);
            result = Math.max(result, solver.getMaxArea());
        }
        return result;
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
