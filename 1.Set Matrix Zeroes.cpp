//APPROACH- 1 - Brute force
//Time Complexity - O(n*m) * O(n+m)
//Space Complexity - O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    //replacing row element before i to -1 
                    int ind = i - 1;
                    while(ind >= 0){
                        if(matrix[ind][j] != 0){
                            matrix[ind][j] = -1;
                        }
                        ind--;
                    }
                    //replacing row element after i to -1 
                    ind = i + 1;
                    while(ind < rows){
                        if(matrix[ind][j] != 0){
                            matrix[ind][j] = -1;
                        }
                        ind++;
                    }
                    //replacing column element above j to -1
                    ind = j - 1;
                    while(ind >= 0){
                        if(matrix[i][ind] != 0){
                            matrix[i][ind] = -1;
                        }
                        ind--;
                    }
                    //replacing column element below j to -1
                    ind = j + 1;
                    while(ind < cols){
                        if(matrix[i][ind] != 0){
                            matrix[i][ind] = -1;
                        }
                        ind++;
                    }
                }
            }
        }
        //replacing -1 to 0
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == -1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};


//APPROACH -2 
