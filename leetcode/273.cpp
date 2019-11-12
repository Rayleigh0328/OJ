// 1,234,567,891
// 2,147,483,647

class Solution {
    const int billion = 1000000000;
    const int million = 1000000;
    const int thousand = 1000;
    
    unordered_map<int, string> num_to_eng{
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"}
    };
    
    string convert(int n){
        assert(0 <= n && n < 1000);
        string ans;
        int hundred = n / 100;
        if (hundred > 0)
            ans += num_to_eng[hundred] + " " + "Hundred";
        n %= 100;
        if (n > 0 && num_to_eng.find(n) != num_to_eng.end()) 
            return (ans.empty()?num_to_eng[n]:ans + " " + num_to_eng[n]);
        int tens = n / 10;
        if (tens > 0) ans += (ans.empty()?"":" ") + num_to_eng[tens * 10];
        n %= 10;
        if (n > 0) ans += (ans.empty()?"":" ") + num_to_eng[n];
        return ans;
    }
    
public:
    string numberToWords(int num) {
        if (num_to_eng.find(num) != num_to_eng.end())
            return num_to_eng[num];
        
        int billion_part = num / billion;
        num %= billion;
        int million_part = num / million;
        num %= million;
        int thousand_part = num / thousand;
        num %= thousand;
        int tail_part = num;
        
        string ans = "";
        if (billion_part > 0)
            ans += convert(billion_part) + " Billion";
        if (million_part > 0)
            ans += " " + convert(million_part) + " Million";
        if (thousand_part > 0)
            ans += " " +convert(thousand_part) + " Thousand";
        if (tail_part > 0)
            ans += " " + convert(tail_part);
        int pos = 0;
        while (ans[pos] == ' ') ++pos;
        return ans.substr(pos);
    }
};
