class Solution {
    public boolean detectCapitalUse(String w) {
        if (w.equals(w.toUpperCase())) return true;
        if (w.equals(w.toLowerCase())) return true;
        if (w.isEmpty()) return true;
        w = w.substring(1);
        if (w.equals(w.toLowerCase())) return true;
        return false;
    }
}
