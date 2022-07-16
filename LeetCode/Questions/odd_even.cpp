class Solution
{
public:
    int countOdds(int low, int high)
    {
        int c = 0;
        int h = 0;
        if (low % 2 == 1)
        {
            c++;
        }
        if (high % 2 == 1 and low != high)
        {
            c++;
        }
        if (low != high)
        {
            if (c == 2)
            {
                h = (high - low) - 1;
            }
            if (c == 0)
            {
                h = (high - low) + 1;
            }
            if (c == 1)
            {
                h = (high - low);
            }
            c += (h / 2);
        }

        return c;
    }
};