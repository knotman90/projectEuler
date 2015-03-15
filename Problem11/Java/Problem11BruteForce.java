package euler;

import java.io.IOException;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;

public class Problem11BruteForce {
	public static int size=4;

	
	public static long getProductElmts(int[][] matrix, int i, int j, int inci, int incj){
		/**
		 * return the product of the tuple of *size element* starting at i,j in the direction of the vector (inci,incj)
		 * **/
		long product =1;
		for(int k=0;k<size;k++){
			int val= matrix[i+k*inci][j+k*incj];
			product*=val;
		}
		return product;
	}

	public static long findMaxProduct(int[][] matrix){
		int m = matrix.length;
		int n = matrix[0].length;
		long max =Long.MIN_VALUE;
		for(int i = 0; i < m; i++){
			for (int j = 0; j < n; j++) {
				//horizontal right
				long prodHor=0, vertDown=0, diagR=0,diagLeft=0;
				if(j<n-size)
					prodHor=getProductElmts(matrix, i, j, 0, 1);

				//verticalDown 
				if(i<n-size)
					vertDown=getProductElmts(matrix, i, j, 1, 0);

				//diagonal  right
				if(j<n-size-1 && i<n-size-1)
					diagR=getProductElmts(matrix, i, j, 1, 1);
				
				//diagonal  left
				if(j>size-1 && i<n-size-1)
					diagLeft=getProductElmts(matrix, i, j, 1, -1);

				max=Math.max(max,Math.max(diagLeft,Math.max(diagR,Math.max(prodHor, vertDown))));
				if(max==70600674){
					System.out.println("i,j "+i+", "+j);
					return max;
				}

			}
		}
		return max;
	}

	public static int [][] readMatrix(String spath){
		Path path = FileSystems.getDefault().getPath(spath, "matrix");
		try {
			String fileContent= new String(Files.readAllBytes(path));
			int[][] matrix= new int [20][20];
			String[] lines = fileContent.split("\n");
			for(int i=0;i<lines.length;i++){
				String[] lineSplitted = lines[i].split(" ");
				for(int j=0;j<lineSplitted.length;j++){
					matrix[i][j] = (Integer.parseInt(lineSplitted[j]));
				}
			}
			//System.out.println(fileContent);
			return matrix;


		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;

	}

	public static void printMatrix(int[][] matrix) {
		for(int i=0;i<matrix.length;i++){
			for(int j=0;j<matrix.length;j++){
				System.out.print(matrix[i][j]+ " ");
			}
			System.out.println();
		}

	}

	public static void main(String[] args) {
		String spath = ".";
		int[][] matrix=readMatrix(spath);
		long max=findMaxProduct(matrix);
		System.out.println("max is "+max);

	}

}

