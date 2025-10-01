/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image. Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.



To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same colour as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same colour as the starting pixel), and so on. Replace the colour of all of the aforementioned pixels with the newColor.


Examples:


Input: image = [ [1, 1, 1], [1, 1, 0], [1, 0, 1] ], sr = 1, sc = 1, newColor = 2

Output: [ [2, 2, 2], [2, 2, 0], [2, 0, 1] ]

Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
  */
class Solution{
    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image,
                                  int sr, int sc, int newColor) {
                                    int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
      vector<vector<int>>ans(image.size(),vector<int>(image[0].size(),0));
      vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
     queue<pair<pair<int,int>,int>>q;
      q.push({{sr,sc},image[sr][sc]});
      visited[sr][sc]=1;
      image[sr][sc] = newColor;
      int dx[4] = {-1, 0, 1, 0};
      int dy[4] = {0, 1, 0, -1};

      while(!q.empty()){
        int first=q.front().first.first;
        int second=q.front().first.second;
        q.pop();
        for(int i=0;i<4;i++){
            int x=dx[i]+first;
            int y=dy[i]+second;
            if(x>=0 and x<image.size() and y>=0 and y<image[0].size() and
            image[x][y]==oldColor and !visited[x][y]){
                q.push({{x,y},image[x][y]});
                visited[x][y]=1;
                image[x][y]=newColor;
            }
        }
      }
      return image;
    }
};
