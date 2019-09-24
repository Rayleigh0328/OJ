import java.util.ArrayList;
import java.util.Collections;

class Solution {

    private static final int INF = 1000000000;

    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i=0; i<arr1.length;++i) a.add(arr1[i]);

        ArrayList<Integer> b = new ArrayList<>();
        for (int i=0; i<arr2.length;++i) b.add(arr2[i]);
        Collections.sort(b);

        // init f
        int[][][] f = new int[a.size()][b.size()][2];
        for (int i=0; i<a.size(); ++i)
            for (int j=0; j<b.size(); ++j)
                for (int k = 0; k<2; ++k)
                    f[i][j][k] = INF;

        // boundary
        // i=0 cases
        for (int j = 0; j<b.size();++j) f[0][j][0] = 0;
        for (int j = 0; j<b.size();++j) f[0][j][1] = 1;

        // j = 0 cases
        // j = 0 and end with b[0]
        if (b.get(0) > a.get(0)) f[1][0][1] = 1;
        for (int i = 2; i<a.size();++i){
            if (a.get(i-1) > a.get(i-2) && b.get(0) > a.get(i-1)) f[i][0][1] = 1;
            else break;
        }
        // j = 0 and end with a[i]
        for (int i=1; i<a.size();++i) {
            if (a.get(i) > a.get(i-1)) f[i][0][0] = min(f[i][0][0], f[i-1][0][0]);
            if (a.get(i) > b.get(0)) f[i][0][0] = min(f[i][0][0], f[i-1][0][1]);
        }

        for (int i=1; i<a.size();++i)
            for (int j=1; j<b.size(); ++j){
                f[i][j][0] = min(f[i][j][0], f[i][j-1][0]);
                if (a.get(i) > a.get(i-1)) {
                    f[i][j][0] = min(f[i][j][0], f[i-1][j][0]);
                    f[i][j][0] = min(f[i][j][0], f[i-1][j-1][0]);
                }

                if (a.get(i) > b.get(j-1)) {
                    f[i][j][0] = min(f[i][j][0], f[i-1][j-1][1]);
                }

                if (a.get(i) > b.get(j))
                    f[i][j][0] = min(f[i][j][0], f[i-1][j][1]);

                f[i][j][1] = min(f[i][j][1], f[i][j-1][1]);
                if (b.get(j) > a.get(i-1)) f[i][j][1] = min(f[i][j][1], f[i-1][j-1][0] + 1);
                if (b.get(j) > b.get(j-1)) f[i][j][1] = min(f[i][j][1], f[i-1][j-1][1] + 1);
            }

        int result = INF;
        for (int j = 0; j<b.size();++j)
            result = min(result, f[a.size() - 1][j][0], f[a.size()-1][j][1]);
        return (result==INF?-1:result);
    }

    private int min(int... args){
        int result = INF;
        for (int i : args)
            result = Math.min(result, i);
        return result;
    }
}
