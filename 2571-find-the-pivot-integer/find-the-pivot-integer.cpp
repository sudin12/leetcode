class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n;
        int sumLeft = l;
        int sumRight = n;

        if(n == 1) return n;
        while(l < r){
            if(sumLeft < sumRight)
                sumLeft += ++l;
            else
                sumRight += --r;
            
            if(sumLeft == sumRight && l + 1 == r - 1)
                return l + 1;
        }
        return -1;
    }
};