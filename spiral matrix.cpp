class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int startrow=0;
        int startcol=0;
        int endcol=col-1;
        int endrow=row-1;
        int c=0;
        int noele=row*col;
        vector<int>finalarr;
        while(c<noele){
        for(int i=startcol;c<noele&&i<=endcol;i++){
            finalarr.push_back(matrix[startrow][i]);
            c++;
        }
        startrow++;
        for(int i=startrow;c<noele&&i<=endrow;i++){
            finalarr.push_back(matrix[i][endcol]);
            c++;
        }
        endcol--;
        for(int i=endcol;c<noele&&i>=startcol;i--){
            finalarr.push_back(matrix[endrow][i]);
            c++;
        }
        endrow--;
        for(int i=endrow;c<noele&&i>=startrow;i--){
            finalarr.push_back(matrix[i][startcol]);
            c++;
        }
        startcol++;
        }
        return finalarr;
    }
};
