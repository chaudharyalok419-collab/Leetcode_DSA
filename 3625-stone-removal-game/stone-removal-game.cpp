class Solution {
public:
    bool canAliceWin(int n) {
        if (n<10) return false;//10
        if (n<19)return true;//9
        if (n<27)return false;//8
        if (n<34)return true;//7
        if(n<40)return false;//6
        if (n<45)return true;//5
        if (n<49)return false;
         return true;

    }
};