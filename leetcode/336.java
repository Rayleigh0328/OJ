class Solution {
    public List<List<Integer>> palindromePairs(String[] words) {
        // trie init
        Trie trie = new Trie();
        for (int i=0;i<words.length;++i){
            String revWord = new StringBuilder(words[i]).reverse().toString();
            trie.insertWord(revWord);
        }

        Map<Integer, Set<Integer>> prefixPalindromes = new HashMap<>();
        Map<Integer, Set<Integer>> suffixPalindromes = new HashMap<>();

        for (int i=0;i<words.length;++i) {
            Manacher manacher = new Manacher(words[i]);
            int[] span = manacher.getSpan();
            // prefix map init
            Set<Integer> prefixSet = new HashSet<>();
            for (int j=1; j<span.length-1;++j){
                if (j-span[j] == 1) prefixSet.add(span[j]);
            }
            prefixPalindromes.put(i, prefixSet);
            // suffix map init
            Set<Integer> suffixSet = new HashSet<>();
            for (int j=1; j<span.length-1;++j){
                if (j + span[j] == 2*words[i].length()+1) suffixSet.add(span[j]);
            }
            suffixPalindromes.put(i, suffixSet);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i=0; i<words.length;++i){
            Set<Integer> resultSet = new HashSet<>();

            Set<Integer> set = trie.getAllPrefixWords(words[i]);
            for (int index : set) {
                Integer diffLength = words[i].length() - words[index].length();
                if (suffixPalindromes.get(i).contains(diffLength)) resultSet.add(index);
            }

            set = trie.getAllWordsStartWithString(words[i]);
            for (int index : set) {
                Integer diffLength = words[index].length() - words[i].length();
                if (prefixPalindromes.get(index).contains(diffLength)) resultSet.add(index);
            }

            resultSet.remove(i);

            for (int index : resultSet){
                result.add(new ArrayList<>(Arrays.asList(i, index)));
            }
        }

        return result;
    }


private class Manacher {

    private int [] a;
    private int [] span;

    Manacher(String originalSt){
        a = new int[originalSt.length() * 2 + 3];
        span = new int[originalSt.length() * 2 + 3];
        for (int i=0; i<span.length;++i) span[i] = 0;
        a[0] = -2;
        for (int i = 0; i<originalSt.length(); ++i){
            a[i*2 + 1] = -1;
            a[i*2 + 2] = originalSt.charAt(i);
        }
        a[originalSt.length() * 2 + 1] = -1;
        a[originalSt.length() * 2 + 2] = -3;

        int c = 0;
        int r = 0;
        for (int i=1; i<a.length-1; ++i){
            int iMirror = 2*c - i;
            if (r > i) span[i] = Math.min(r - i, span[iMirror]);
            while (a[ i-span[i]-1 ] == a[ i+span[i]+1 ]) ++span[i];
            if (i + span[i] > r){
                r = i + span[i];
                c = i;
            }
        }
    }

    private Character convertIntegerBackToChar(int x){
        if (x == -1) return '#';
        if (x == -2) return '^';
        if (x == -3) return '$';
        return (char) x;
    }

    public String getPaddedString(){
        StringBuilder sb = new StringBuilder();
        for (int i=0;i<a.length;++i) sb.append(convertIntegerBackToChar(a[i]));
        return sb.toString();
    }

    public int[] getPaddedArray(){
        return a;
    }

    public int[] getSpan(){
        return span;
    }

    public int getLongestPalindromeLength(){
        int len = 0;
        for (int i=1; i<span.length; ++i)
            if (span[i] > len) len = span[i];
        return len;
    }

    public List getLongestPalindromeLocation(){
        int maxLen = getLongestPalindromeLength();
        List list = new ArrayList<Integer>();
        for (int i=0;i<span.length;++i)
            if (span[i] == maxLen) list.add(i);
        return list;
    }

    public String getPalindrome(Integer loc){
        return getPalindrome(loc, span[loc]);
    }

    public String getPalindrome(int loc, int length){
        StringBuilder sb = new StringBuilder();
        for (int i=loc - length; i<=loc+length;++i)
            if (a[i] > 0) sb.append((char)a[i]);
        return sb.toString();
    }

}

private class Trie {
    private class TrieNode{
        List<Integer> wordsEndHere;
        Map<Character, TrieNode> next;

        public TrieNode(){
            wordsEndHere = new ArrayList<>();
            next = new HashMap<>();
        }
    }

    private TrieNode root;
    private ArrayList dict;

    public Trie(){
        root = new TrieNode();
        dict = new ArrayList();
    }

    public Trie(String[] a){
        this();
        for (int i=0;i<a.length;++i){
            insertWord(a[i]);
        }
    }

    public ArrayList getDict() {
        return dict;
    }

    public void insertWord(String st){

        int index = dict.size();
        dict.add(st);

        TrieNode currentNode = root;
        for (int i=0; i<st.length(); ++i){
            Character ch = st.charAt(i);
            TrieNode nextNode = currentNode.next.get(ch);
            if (nextNode == null){
                nextNode = new TrieNode();
                currentNode.next.put(ch, nextNode);
            }
            currentNode = nextNode;
        }

        currentNode.wordsEndHere.add(index);
    }

    private TrieNode search(String st){
        TrieNode currentNode = root;
        for (int i=0; i<st.length();++i){
            Character ch = st.charAt(i);
            currentNode = currentNode.next.get(ch);
            if (currentNode == null) return null;
        }
        return currentNode;
    }

    public boolean checkWordInDict(String st){
        TrieNode node = search(st);
        if (node == null) return false;
        return !node.wordsEndHere.isEmpty();
    }

    public Set<Integer> getAllPrefixWords(String st){
        TrieNode currentNode = root;
        Set<Integer> indexSet = new HashSet<>();
        for (int i=0; i<st.length();++i){
            indexSet.addAll(currentNode.wordsEndHere);
            Character ch = st.charAt(i);
            currentNode = currentNode.next.get(ch);
            if (currentNode == null) return indexSet;
        }
        return indexSet;
    }

    public Set<Integer> getAllWordsInTrie() {
        return getAllWordsStartWithString("");
    }

    public Set<Integer> getAllWordsStartWithString(String st){
        return getAllWordsStartWithString(search(st));
    }

    private Set<Integer> getAllWordsStartWithString(TrieNode node){
        Set<Integer> result = new HashSet<>();
        dfs(node, result);
        return result;
    }

    private void dfs(TrieNode node, Set<Integer> indexSet){
        if (node == null) return;
        indexSet.addAll(node.wordsEndHere);
        for (Character ch : node.next.keySet()){
            dfs(node.next.get(ch), indexSet);
        }
    }

}
    
}
