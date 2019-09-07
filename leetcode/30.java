import java.util.*;

class Solution {

    HashMap<String, Integer> wordIndexMap;
    Integer dictWordLength;

    private ArrayList<Integer> constructFingerPrint(String st){
        ArrayList<Integer> result = new ArrayList<>();
        int pos = 0;
        while (pos < st.length()) {
            String tmpStr = st.substring(pos, Math.min(st.length(),pos + dictWordLength));
            if (wordIndexMap.containsKey(tmpStr))
                result.add(wordIndexMap.get(tmpStr));
            else
                result.add(-1);
            pos += dictWordLength;
        }
        return result;
    }

    private boolean checkFingerPrintMatch(LinkedList<Integer> x, ArrayList<Integer> y){
        if (x.size() != y.size()) return false;

        ArrayList<Integer> z = new ArrayList<>();
        for (Integer e : x) z.add(e);
        Collections.sort(z);
        for (int i=0;i<y.size();++i)
            if (!y.get(i).equals(z.get(i))) return false;
        return true;
    }

    private int reconstructAnswer(int offset, int left){
        return offset + left * dictWordLength;
    }

    public List<Integer> findSubstring(String st, String[] dict) {
        List<Integer> result = new LinkedList<>();
        if (dict.length == 0 || dict[0].length() ==0 || st.length() == 0 ) return result;
        // construct wordIndexMap: string --> integer
        wordIndexMap = new HashMap();
        Integer count = 0;
        for (int i=0;i<dict.length;++i)
            if (!wordIndexMap.containsKey(dict[i])) wordIndexMap.put(dict[i], count++);

        // use wordIndexMap to create a finger print for dict
        ArrayList<Integer> dictFingerPrint = new ArrayList<>();
        for (int i=0;i<dict.length;++i) dictFingerPrint.add(wordIndexMap.get(dict[i]));
        Collections.sort(dictFingerPrint);

        // let dictWordLength denote the length of each word in dict
        // for offset in [0, dictWordLength - 1) construct indexArray for st.substr(offset)
        // find match finger print and reconstruct the index in st
        dictWordLength = dict[0].length();
        for (int offset = 0; offset < dictWordLength; ++offset){
            ArrayList<Integer> stFingerPrint = constructFingerPrint(st.substring(offset));
            LinkedList<Integer> queue = new LinkedList<>();
            int left = 0;
            int right = 0;
            while (queue.size() < dict.length && right < stFingerPrint.size())
                queue.add(stFingerPrint.get(right++));
            if (checkFingerPrintMatch(queue, dictFingerPrint))
                result.add(reconstructAnswer(offset, left));
            while (right < stFingerPrint.size()){
                queue.removeFirst();
                ++left;
                queue.addLast(stFingerPrint.get(right++));
                if (checkFingerPrintMatch(queue, dictFingerPrint))
                    result.add(reconstructAnswer(offset, left));
            }
        }
        return result;
    }
}