/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this
 * license Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package praweek12;

import java.util.Random;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Main {
    static final int MAX = 3;
    static final int MAX_THREAD = 3;
    static int[][] matrixA = new int[MAX][MAX];
    static int[][] matrixB = new int[MAX][MAX];
    static int[][] matrixC = new int[MAX][MAX];
    static int[][] matrixD = new int[MAX][MAX];
    static int step_i = 0;

    static class Worker implements Runnable {
        int i;

        Worker(int i) {
            this.i = i;
        }

        @Override
        public void run() {
            for (int j = 0; j < MAX; j++) {
                for (int k = 0; k < MAX; k++) {
                    matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                matrixA[i][j] = rand.nextInt(10);
                matrixB[i][j] = rand.nextInt(10);
            }
        }

        System.out.println("Matrix A");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                System.out.print(matrixA[i][j] + " ");
            }
            System.out.println();
        }

        System.out.println("Matrix B");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                System.out.print(matrixB[i][j] + " ");
            }
            System.out.println();
        }

        Thread[] threads = new Thread[MAX_THREAD];

        for (int i = 0; i < MAX_THREAD; i++) {
            threads[i] = new Thread(new Worker(step_i++));
            threads[i].start();
        }

        for (int i = 0; i < MAX_THREAD; i++) {
            try {
                threads[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        System.out.println("Multiplication of A and B with multithread");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                System.out.print(matrixC[i][j] + " ");
            }
            System.out.println();
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                matrixD[i][j] = 0;
                for (int k = 0; k < MAX; k++) {
                    matrixD[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }

        System.out.println("Multiplication of A and B without multithread");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                System.out.print(matrixD[i][j] + " ");
            }
            System.out.println();
        }
    }
}
