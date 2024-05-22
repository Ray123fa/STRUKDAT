/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package responsi10;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class LatihanFile {
    public static void main(String[] args) {
            try {
                    File f = new File(
                                    "C:\\Users\\ray16\\OneDrive\\Documents\\STIS\\Semester_4\\PBO\\after_uts\\src\\responsi10\\objek.dat");
                    FileInputStream fis = new FileInputStream(f);
                    ObjectInputStream ois = new ObjectInputStream(fis);
                    Mahasiswa mhs = (Mahasiswa) ois.readObject();
                    System.out.println(mhs.getNim());
                    System.out.println(mhs.getNama());
                    ois.close();
                    fis.close();
            } catch (FileNotFoundException ex) {
                    System.err.println("File tidak ditemukan");
            } catch (IOException ex) {
                    System.err.println("File gagal dibaca");
            } catch (ClassNotFoundException ex) {
                    System.err.println("Format File salah");
            }
    }
}
