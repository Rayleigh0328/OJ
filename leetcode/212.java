class Solution {

    Set<String> wordsFound;
    int boardRowCount;
    int boardColumnCount;
    char [][] board;
    Trie trie;

    public List<String> findWords(char[][] board, String[] words) {
        trie = new Trie(words);
        wordsFound = new HashSet<>();

        boardRowCount = board.length;
        if (boardRowCount == 0) return wordsFound.stream().collect(Collectors.toList());
        boardColumnCount = board[0].length;
        if (boardColumnCount == 0) return wordsFound.stream().collect(Collectors.toList());
        this.board = board;

        Set<Position> visited = new HashSet<>();
        for (int i=0;i<boardRowCount;++i)
            for (int j=0;j<boardColumnCount;++j) {
                Position p = new Position(i,j);
                if (trie.root.next.get(getChar(p)) != null)
                    solve(p, trie.root.next.get(getChar(p)), visited);
            }
        return wordsFound.stream().collect(Collectors.toList());
    }

    private Set<Position> buildNextPosSet(Position pos, Trie.TrieNode node, Set<Position> visited){
        List<Position> candidateList = new LinkedList<>();
        candidateList.add(new Position(pos.x - 1, pos.y));
        candidateList.add(new Position(pos.x + 1, pos.y));
        candidateList.add(new Position(pos.x , pos.y-1));
        candidateList.add(new Position(pos.x , pos.y+1));
        Set<Position> result = new HashSet<>();
        for (Position nextPos : candidateList)
            if (inBoundary(nextPos) &&
                    node.next.get(getChar(nextPos)) != null &&
                    !visited.contains(nextPos)
               )
                result.add(nextPos);
        return result;
    }

    private void solve(Position pos, Trie.TrieNode node, Set<Position> visited){
        if (!node.wordsEndHere.isEmpty()) wordsFound.add((String) trie.getDict().get(node.wordsEndHere.get(0)));
        visited.add(pos);
        Set<Position> nextPosSet = buildNextPosSet(pos, node, visited);
        for (Position nextPos : nextPosSet)
            solve(nextPos, node.next.get(getChar(nextPos)), visited);
        visited.remove(pos);
    }

    private Character getChar(Position pos){
        return board[pos.x][pos.y];
    }

    private boolean inBoundary(Position pos){
        if (pos.x < 0) return false;
        if (pos.x >= boardRowCount) return false;
        if (pos.y < 0) return false;
        if (pos.y >= boardColumnCount) return false;
        return true;
    }
}

class Position{
    public int x;
    public int y;

    public Position() {
        this(0,0);
    }

    public Position(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Position position = (Position) o;

        if (x != position.x) return false;
        return y == position.y;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}

public class Trie {

    public static class TrieNode{
        List<Integer> wordsEndHere;
        Map<Character, TrieNode> next;

        public TrieNode(){
            wordsEndHere = new ArrayList<>();
            next = new HashMap<>();
        }
    }

    public TrieNode root;
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