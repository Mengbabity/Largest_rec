class Solution {
public:
	int largestRectangleArea(vector<int> heights) {
        int res=0;
        heights.push_back(0);
        int n=heights.size();
        vector<int> index;
        int flag=0;
        
        for(int i=0;i<n;i++)
        {
            while(index.size()>0 && heights[index.back()]>=heights[i])
            {
                int h=heights[index.back()];
                index.pop_back();
                
                if(index.size()==0)
                    flag=-1;
                else
                    flag=index.back();
                
                res=max(res,h*(i-flag-1));
            }
            index.push_back(i);
        }
        
        return res;
	}
};
