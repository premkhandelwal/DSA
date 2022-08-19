class Solution {
public:
    void f(vector<vector<int>>& image, int i, int j, int color, int val){
//         Check overflow, underflow conditions, if color of the acquired cell is already filled with new color and if the cell value is not equal to start cell 
        if(i < 0 || j < 0 || i>=image.size() || j>= image[0].size() || image[i][j] == color || image[i][j] != val){
            return;
        }
//         Assign new color to cell
        image[i][j] = color;
        f(image,  i - 1, j, color, val);
        f(image,  i, j + 1, color, val);
        f(image,  i + 1, j, color, val);
        f(image,  i, j - 1, color, val);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //Get the color of given cell         
        int val = image[sr][sc];
        f(image, sr, sc, color, val);
        return image;
        
    }
    
};
