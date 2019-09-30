class Solution {
    public boolean isValid(String S) {
        ArrayList<Character> a = new ArrayList<>();
        for (int i=0;i<S.length();++i){
            a.add(S.charAt(i));
            if (a.size() >= 3 &&
                    a.get(a.size() - 3).equals('a') &&
                    a.get(a.size() - 2).equals('b') &&
                    a.get(a.size() - 1).equals('c')
            ) {
                a.remove(a.size()-1);
                a.remove(a.size()-1);
                a.remove(a.size()-1);
            }
        }
        return a.isEmpty();
    }
}
