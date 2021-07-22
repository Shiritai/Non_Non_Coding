/**
 * Created by Eroiko at 2021/07/21
 */
package Java;
public class Matrix_Determinant {
    public static int [][] slice(int [][] matrix, int pivot){
        int len = matrix.length - 1;
        var res = new int [len][len];
        for (int i = 0; i < len; ++i){
            for (int j = 0, diff = 0; j < len; ++j){
                if (j == pivot){
                    diff = 1;
                };
                res[i][j] = matrix[i + 1][(j + diff) % matrix.length];
            }
        }
        return res;
    }
    
    /**
     * Use recursion to find the determine of one matrix, with no "square" check
     * @param matrix a n * n matrix
     * @return the determine of given matrix
     */
    public static int determinant(int[][] matrix) {
        int res = 0;
        if (matrix.length > 2){
            for (int i = 0, sign = 1; i < matrix.length; ++i, sign *= -1){
                res += sign * matrix[0][i] * determinant(slice(matrix, i));
            }
        }
        else if (matrix.length == 2){ // 2 * 2 matrix, for better performance
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        else { // 1 * 1 matrix
            return matrix[0][0];
        }
        return res;
    }

    public static void main(String [] args){
        System.out.println(determinant(new int [][]{
            {2, 5, 3},
            {1, -2, -1},
            {1, 3, 4}
        }));
    }
}
