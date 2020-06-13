class BrowserHistory {
    
    vector<string> a;
    int index;
    
public:
    BrowserHistory(string homepage) {
        a.clear();
        a.push_back(homepage);
        index = 0;
    }
    
    void visit(string url) {
        // printf("visit\n");
        // clear 
        while (a.size() > index+1){
            a.pop_back();
        }
        // visit
        a.push_back(url);
        index = a.size()-1;
    }
    
    string back(int steps) {
        // printf("back\n");
        index = max(index - steps, 0);
        return a[index];
    }
    
    string forward(int steps) {
        // printf("forward\n");
        index = min(index + steps, (int)(a.size())-1);
        return a[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
