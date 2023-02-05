class Solution {
public:
    void queue(vector<vector<int>> &image, int sr, int sc, vector<vector<int>> &explored) {
        explored[sr][sc] = 1;
        if(sr - 1 >= 0 && image[sr-1][sc] == image[sr][sc] && !explored[sr-1][sc])
            queue(image, sr-1, sc, explored);
        if(sr + 1 < image.size() && image[sr+1][sc] == image[sr][sc] && !explored[sr+1][sc])
            queue(image, sr+1, sc, explored);
        if(sc - 1 >= 0 && image[sr][sc-1] == image[sr][sc] && !explored[sr][sc-1])
            queue(image, sr, sc-1, explored);
        if(sc + 1 < image[0].size() && image[sr][sc+1] == image[sr][sc] && !explored[sr][sc+1])
            queue(image, sr, sc+1, explored);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> explored(image.size(), vector<int>(image[0].size(), 0));

        queue(image, sr, sc, explored);

        for(unsigned int r = 0; r < explored.size(); r++) {
            for(unsigned int c = 0; c < explored[r].size(); c++) {
                if(explored[r][c]) image[r][c] = color;
            }
        }

        return image;
    }
};