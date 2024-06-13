/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this
 * license Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package responsi12;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class LatihanThread {
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Thread t = new Thread(new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 10; i++) {
                    System.out.println("Thread t: " + i);
                }
            }
        });
        t.start();
        for (int i = 0; i < 10; i++) {
            System.out.println("Main Thread: " + i);
        }
    }
}
