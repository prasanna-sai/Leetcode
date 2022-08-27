class Solution
{
    public:
    //Start from top right, if value is less than that target, then it can't be in that row. if value is greater than target, then it can't be in that column
        bool searchMatrix(vector<vector<int>>& m, int target)
        {
            int r = m.size();
            int c = m[0].size();
            int i = 0;
            int j = c-1;
            while(i<r && j>=0)
            {
                if(m[i][j] < target)
                {
                    i++;
                }
                else if(m[i][j] > target)
                {
                    j--;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
};