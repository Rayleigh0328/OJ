class MyCalendar {
public:

	vector<int> v_start;
	vector<int> v_end;

    MyCalendar() {
    }
    
    bool conflict(int left, int right){
    	for (int i=0;i<v_start.size();++i)
    		if (!(right <= v_start[i] || left >= v_end[i])) return true; 
    	return false;
    }

    bool book(int start, int end) {
    	if (!conflict(start, end)) {
    		v_start.push_back(start);
    		v_end.push_back(end);
    		return true;
    	}
    	else{
    		return false;
    	}
    }
};
