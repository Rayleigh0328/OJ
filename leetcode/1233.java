class Node{
    boolean isEnd;
    HashMap<String, Node> next;
    
    Node(){
        isEnd = false;
        next = new HashMap<String, Node>();
    }
}

class Solution {
    
    void insert(String[] arr, int pos, Node n){
        if (pos == arr.length) {
            n.isEnd = true;
            return;
        }
        if (n.next.get(arr[pos]) == null){
            n.next.put(arr[pos], new Node());
            insert(arr, pos + 1, n.next.get(arr[pos]));
        }
        else {
            if (n.next.get(arr[pos]).isEnd) return;
            insert(arr, pos+1, n.next.get(arr[pos]));
        }
    }
    
    void output(Node n, String current, List<String> ans){
        if (n.isEnd) {
            ans.add(current.substring(0, current.length()-1));
            return;
        }
        for (Map.Entry<String, Node>entry : n.next.entrySet()){
            output(entry.getValue(), current+ entry.getKey() + "/", ans);
        }
    }
    
    public List<String> removeSubfolders(String[] folder) {
        Node root = new Node();
        
        for (int i=0;i<folder.length;++i){
            // System.out.println(folder[i]);
            String[] arr = folder[i].split("/");
            // for (String s : arr) System.out.println(s);
            insert(arr, 0, root);
        }
        
        List<String> ansList = new LinkedList<String>(); 
        output(root, "", ansList);
        return ansList;
    }
}
