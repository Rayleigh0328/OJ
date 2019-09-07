import java.util.HashMap;
import java.util.Map;

class Solution {

    private boolean checkFingerPrint(Map<Character, Integer> current, Map<Character, Integer> mode){
        for (Character ch : mode.keySet()){
            if (current.get(ch) == null || current.get(ch) < mode.get(ch))
                return false;
        }
        return true;
    }

    public String minWindow(String s, String t) {
        // create finger print of t : alphabet --> int
        Map<Character, Integer> mode= new HashMap<>();
        for (int i=0;i<t.length();++i){
            Character key = t.charAt(i);
            if (mode.get(key) == null) mode.put(key, 1);
            else mode.put(key, mode.get(key) + 1);
        }

        Map<Character, Integer> current= new HashMap<>();
        int ansLeft=-1;
        int ansRight=s.length()+1;
        int left = 0;
        int right = 0;
        while(true) {
            // expand right
            while (!checkFingerPrint(current, mode) && right < s.length()) {
                Character key = s.charAt(right++);
                if (current.get(key) == null) current.put(key, 1);
                else current.put(key, current.get(key) + 1);
            }
            if (right == s.length() && !checkFingerPrint(current, mode)) break;
            // expand left
            while (checkFingerPrint(current, mode)){
                Character key = s.charAt(left++);
                current.put(key, current.get(key) - 1);
            }
            if (right - left < ansRight - ansLeft) {
                ansRight = right;
                ansLeft = left;
            }
        }
        if (ansLeft == -1) return "";
        else return s.substring(ansLeft - 1, ansRight );
    }
}
