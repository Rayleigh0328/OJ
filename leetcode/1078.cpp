class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        ArrayList<String> list = new ArrayList();
        String[] a = text.split(" +");
        // for (String s : a) System.out.println(s);
        for (int i=2; i<a.length; ++i)
            if (a[i-2].equals(first) && a[i-1].equals(second)){
                list.add(a[i]);
                // System.out.println("find match");
            }
        return list.toArray(new String[list.size()]);
    }
}
