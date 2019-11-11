
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

class Solution {
    // state (x,y) x is the amount of water in jug1, y is the amount of water in jug2
    // possible operation: 
    // 1) fill jug1
    // 2) fill jug2
    // 3) pour water from jug1 to jug2
    // 4) pour water from jug2 to jug1
    // 5) empty jug1
    // 6) empty jug2
    
    unordered_set<pair<int,int>, pair_hash> visited;
    int goal;
    
    bool attempt(int x, int y, queue<pair<int,int>>&que){
        if (x == goal || y == goal || x + y == goal) return true;
        if (visited.find({x,y}) != visited.end()) return false;
        visited.emplace(pair<int,int>(x,y));
        que.emplace(pair<int,int>(x,y));
        return false;
    }
    
public:
    bool canMeasureWater(int x, int y, int z) {
        goal = z;
        queue<pair<int, int>> que;
        que.push({0,0});
        visited.emplace(pair<int,int>(x,y));
        int p, q, amount;
        while (!que.empty()){
            p = que.front().first;
            q = que.front().second;
            que.pop();
            
            if (attempt(x,q,que)) return true;
            if (attempt(p,y,que)) return true;
            if (attempt(0,q,que)) return true;
            if (attempt(p,0,que)) return true;
            amount = min(p, y-q);
            if (attempt(p-amount, q+amount, que)) return true;
            amount = min(x - p, q);
            if (attempt(p+amount, q-amount, que)) return true;
        }
        return false;
    }
};

