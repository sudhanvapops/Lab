import java.util.Scanner;

public class MatrixAddition {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of rows (m): ");
        int m = sc.nextInt();

        System.out.print("Enter number of columns (n): ");
        int n = sc.nextInt();

        int[][] matrix1 = new int[m][n];
        int[][] matrix2 = new int[m][n];
        int[][] result = new int[m][n];

        System.out.println("\nEnter elements for Matrix 1:");
        inputMatrix(matrix1, sc);

        System.out.println("\nEnter elements for Matrix 2:");
        inputMatrix(matrix2, sc);

        addMatrices(matrix1, matrix2, result);

        System.out.println("\n Matrix 1:");
        displayMatrix(matrix1);
        System.out.println("\nMatrx 2:");
        displayMatrix(matrix2);
        System.out.println("\nResultant Matrix after Addition:");
        displayMatrix(result);

        sc.close();
    }


    public static void inputMatrix(int[][] matrix, Scanner sc) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
    }


    public static void addMatrices(int[][] matrix1, int[][] matrix2, int[][] result) {
        for (int i = 0; i < matrix1.length; i++) {
            for (int j = 0; j < matrix1[0].length; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
    }


    public static void displayMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}
