class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {

        for(auto &row: image){
            reverse(row.begin(), row.end());

            for(int &each: row){
                each=each^1;
            }
        }

        return image;

    }
};