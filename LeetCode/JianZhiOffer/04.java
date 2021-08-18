class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        int maxY = matrix.length - 1;
        int maxX = matrix[0].length - 1;
        int nowX = maxX, nowY = 0;
        while (true) {
            if (nowX < 0 || nowY > maxY)
                return false;
            if (matrix[nowY][nowX] < target)
                nowY++;
            else if (matrix[nowY][nowX] > target)
                nowX--;
            else
                return true;
        }
    }
}
