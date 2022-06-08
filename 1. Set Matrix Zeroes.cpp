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
//Time Complexity - O(n*m) + O(n*m)
//Space Complexity - O(n)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dummy1(rows,-1), dummy2(cols,-1);
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    dummy1[i] = 0;
                    dummy2[j] = 0;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(dummy1[i] == 0 || dummy2[j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//APPROACH -3 Optimized
//Time Complexity - O(2*n*m)
//Space Complexity - O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colZero = 1, rows = matrix.size(), cols=matrix[0].size();
        for(int i = 0; i < rows; i++){
            //checking if 0 is present in the 0th column or not
            if(matrix[i][0] == 0){
                colZero = 0;
            }
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
   //traversing in the reverse direction and
  //checking if the row or col has 0 or not
  //and setting values of matrix accordingly.
        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 1; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            if(colZero == 0){
                matrix[i][0] = 0;
            }
        }
    }
};
