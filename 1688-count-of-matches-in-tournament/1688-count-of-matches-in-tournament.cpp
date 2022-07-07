class Solution {
public:
    int teams;
    int matches;
    int numberOfMatches(int n) {
        if(n==1)
        {
            return 0;
        }
        teams=n;
        while(teams>2)
        {
            if(teams%2==0)
            {
                teams=teams/2;
                matches+=teams;
            }
            else
            {
                teams=teams/2;
                matches+=teams;
                teams++;
            }
        }
        return (matches+1);
        
    }
};