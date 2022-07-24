class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        long int sum=0;
        while(n>0)
        {
            int r=n%10;
            sum=sum*10;
            sum+=r;
            n=n/10;
        }
        if(sum==x)
        {
            return true;
        }
        return false;
    }
};