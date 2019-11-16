class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        for (const auto &element : regions)
            for (int i=1;i<element.size();++i)
                parent[ element[i] ] = element[0];
        
        string current = region1;
        unordered_set<string> path{current};
        while (parent.find(current) != parent.end()){
            current = parent[current];
            path.emplace(current);
        }
            
        current = region2;
        if (path.find(current) != path.end()) return current;
        while (parent.find(current) != parent.end()){
            current = parent[current];
            if (path.find(current) != path.end()) return current;
        }
        
        return "NO SOLUTION";
    }
};
