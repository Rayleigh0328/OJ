class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int cnt_s[10];
        int cnt_g[10];
        for (int i=0;i<10;++i) cnt_s[i] = cnt_g[i] = 0;
        
        int bull = 0, cow = 0;
        for (int i=0;i<secret.length();++i)
            if (secret[i] == guess[i]) ++bull;
            else
            {
                ++cnt_s[secret[i]-'0'];
                ++cnt_g[guess[i]-'0'];
            }
        for (int i=0;i<10;++i)
            cow += min(cnt_s[i], cnt_g[i]);
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};