class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> matrix){
      int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> prefixSum(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            prefixSum[i][j] = matrix[i][j];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++)
            prefixSum[i][j] += prefixSum[i][j-1]; // prefix sum for each row
    }
    int startCol = 0, endCol = 0, startRow = 0, endRow = 0;
    int maxSize = 0;
    // use a map to first store the row for sum if it was not present earlier
    // else we calculate the result regarding the particular sum
    for(int firstCol=0;firstCol<m;firstCol++){
        for(int secondCol=firstCol;secondCol<m;secondCol++){
            int tmp[n]; // it stores the sum between two columns for each row
            for(int row=0;row<n;row++)
                tmp[row] = prefixSum[row][secondCol] - (firstCol>0 ? prefixSum[row][firstCol-1] : 0);
            int curSum = 0;
            unordered_map<int,int> rowSumMap;
            rowSumMap[0] = -1;
            for(int curRow=0;curRow<n;curRow++){
                curSum += tmp[curRow];
                if(rowSumMap.count(curSum)) {
                    int subMatrixSize = (secondCol - firstCol + 1)*(curRow - rowSumMap[curSum]);
                    if(subMatrixSize > maxSize){
                        maxSize = subMatrixSize;
                        startCol = firstCol;
                        endCol = secondCol;
                        startRow = rowSumMap[curSum] + 1;
                        endRow = curRow;
                    }
                } else {
                    rowSumMap[curSum] = curRow;
                }
            }
        }
    }
    // storing the answer matrix containing the largest rectangle coordinates
    vector<vector<int>> ans;
    for(int i=startRow;i<=endRow;i++){
        vector<int> tmp;
        for(int j=startCol;j<=endCol;j++){
            tmp.push_back(matrix[i][j]);
        }
        ans.push_back(tmp);
    }
    return ans;
    
      
  }
};