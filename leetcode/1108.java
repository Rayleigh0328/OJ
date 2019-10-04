class Solution {
     public String defangIPaddr(String address) {
        String[] part = address.split("\\.");
         // System.out.println(part.length);
        StringBuilder sb = new StringBuilder();
        for (String x : part){
            sb.append(x);
            sb.append("[.]");
        }
        return sb.substring(0, sb.length() - 3);
    }
}
