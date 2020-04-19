class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> dish_set;
        for (auto &order : orders) dish_set.emplace(order[2]);
        
        map<int, map<string, int>> record;
        int table;
        string dish;
        for (auto &order : orders){
            table = stoi(order[1]);
            dish = order[2];
            ++record[table][dish];
        }
        
        vector<vector<string>> result;
        
        // table header
        vector<string> header;
        header.push_back("Table");
        for (auto &dish : dish_set) header.push_back(dish);
        result.push_back(header);
        
        // table content
        for (auto &table : record){
            vector<string> row;
            row.push_back(to_string(table.first));
            for (auto &dish : dish_set)
                row.push_back(to_string(table.second[dish]));
            result.push_back(row);
        }
        
        return result;
    }
};
