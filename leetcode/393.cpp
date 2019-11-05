class Solution {
public:
    bool validUtf8(vector<int>& a) {
        int mask1 = 0x80; // 1000 0000, if type1 then data&mask1 == 0
        int mask2 = 0xE0; // 1110 0000, if type2 then data&mask2 == 0xC0
        int mask3 = 0xF0; // 1111 0000, if type3 then data&mask3 == 0xE0
        int mask4 = 0xF8; // 1111 1000, if type4 then data&mask4 == 0xF0
        int follow_mask = 0xC0; // 1100 0000, if valid following data data&follow_mask = 0x80
        
        int n = a.size();
        int i = 0,j;
        
        while (i<n){
            // printf("first data is %d\n", a[i]);
            // printf("%d, %d\n",a[i+2], (a[i+2]&follow_mask), 0x80);
            if ((a[i]&mask1)==0){
                // printf("type 1\n");
                j = i+1;
            }
            else if ((a[i]&mask2) == 0xC0){
                // printf("type 2\n");
                if(i+1>=n) return false;
                if ((a[i+1]&follow_mask )!= 0x80) return false;
                j = i+2;
            }
            else if ((a[i]&mask3) == 0xE0){
                // printf("type 3\n");
                if(i+2>=n) return false;
                if ((a[i+1]&follow_mask) != 0x80) return false;
                if ((a[i+2]&follow_mask) != 0x80) return false;
                j = i+3;
            }
            else if ((a[i]&mask4) == 0xF0){
                // printf("type 4\n");
                if(i+3>=n) return false;
                if ((a[i+1]&follow_mask) != 0x80) return false;
                if ((a[i+2]&follow_mask) != 0x80) return false;
                if ((a[i+3]&follow_mask) != 0x80) return false;
                j = i+4;
            }
            else return false;
            i = j;
        }
        
        return true;
    }
};
