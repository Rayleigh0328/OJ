class Solution {

    private String checkSpecial(long value){
        if (value < 10) return Long.toString(value-1);

        long special = 10l;
        while (special <= 1000000000000000000l){
            if (value == special) return Long.toString(special - 1);
            if (value == special + 1) return Long.toString(special - 1);
            if (value == special - 1) return Long.toString(special + 1);
            special *= 10;
        }
        return null;
    }

    private int getLength(long value){
        return Long.toString(value).length();
    }

    private long constructPalindrome(long firstHalf, boolean isOddLength){
        long tmp = firstHalf;
        if (isOddLength) tmp /= 10;
        String tmpSt = Long.toString(tmp);
        long result = firstHalf;
        for (int i=tmpSt.length()-1; i >= 0; --i){
            result = result * 10 + (tmpSt.charAt(i) - '0');
        }
        return result;
    }

    private long chooseBetter(long original, long ans1, long ans2){
        long diff1 = Math.abs(ans1 - original);
        long diff2 = Math.abs(ans2 - original);

        if (diff1 < diff2) return ans1;
        if (diff2 < diff1) return ans2;
        if (ans1 < ans2) return ans1;
        return ans2;
    }

    public String nearestPalindromic(String st) {
        long originalValue = Long.valueOf(st);
        if (checkSpecial(originalValue) != null) return checkSpecial(originalValue);

        boolean isOddLength = ((st.length() & 1) == 1);
        long firstHalf = Long.valueOf(st.substring(0, (st.length()+1) / 2));

        // try firstHalf - 1, firstHalf + 1, firstHalf
        long currentResult = constructPalindrome(firstHalf, isOddLength);
        if (currentResult == originalValue) currentResult = 0;
        if (Long.toString(firstHalf - 1).length() == Long.toString(firstHalf).length()){
            long candidate = constructPalindrome(firstHalf - 1, isOddLength);
            currentResult = chooseBetter(originalValue, currentResult, candidate);
        }
        if (Long.toString(firstHalf + 1).length() == Long.toString(firstHalf).length()){
            long candidate = constructPalindrome(firstHalf + 1, isOddLength);
            currentResult = chooseBetter(originalValue, currentResult, candidate);
        }
        return Long.toString(currentResult);
    }
}
