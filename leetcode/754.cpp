class Solution {
public:
    int reachNumber(int target) {
        if (target == 2) return 3;
        target = abs(target);
        int pos = 0, step = 0;
        while (pos < target) pos += ++step;
        // printf("pos: %d, target: %d, step: %d\n", pos, target, step);
        if (pos == target) return step;
        if ((pos + target)&1){
            if (step&1) return step + 2;
            else return step + 1;
        }
        else return step;
    }
};
