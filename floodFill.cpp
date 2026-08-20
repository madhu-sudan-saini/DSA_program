class Solution {
public:

    void dfs(vector<vector<int>>& image, int r, int c, int originalimage, int color)
    {
        int m = image.size();
        int n = image[0].size();

        if(r < 0 || r >= m || c < 0 || c >= n)
        {
            return;
        }

        if(image[r][c] != originalimage)
        {
            return;
        }

        image[r][c]=color;

        dfs(image,r-1,c,originalimage,color);

        dfs(image,r+1,c,originalimage,color);

        dfs(image,r,c-1,originalimage,color);

        dfs(image,r,c+1,originalimage,color);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int originalimage = image[sr][sc];

        if(originalimage == color)
        {
            return image;
        }

        dfs(image,sr,sc,originalimage,color);
        return image;
    }
};
