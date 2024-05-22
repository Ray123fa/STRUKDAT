/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package responsi10;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Database implements Serializable{
    public static Database instance;
    private ArrayList<Mahasiswa> data = new ArrayList<>();

    private Database(){}

    public static synchronized Database getInstance(){
        loadFile();
        if(instance == null){
            instance = new Database();
        }
        
        return instance;
    }

    public void insertMahasiswa(Mahasiswa mahasiswa){
        data.add(mahasiswa);
        updateFile();
    }

    public List<Mahasiswa> getListMahasiswa(){
        return data;
    }
    
    private static void loadFile(){
        try{
            File f = new File("C:\\Users\\ray16\\OneDrive\\Documents\\STIS\\Semester_4\\PBO\\after_uts\\src\\responsi10\\database.dat");
            try (FileInputStream fis = new FileInputStream(f); 
               ObjectInputStream ois = new ObjectInputStream(fis)) {
                    instance = (Database) ois.readObject();
            }
        } catch (FileNotFoundException ex) {
            System.err.println("File tidak ditemukan");
        } catch (IOException ex) {
            System.err.println("File gagal dibaca");
        } catch (ClassNotFoundException ex){
            System.err.println("Format file salah");
        }
    }
    
    private void updateFile(){
        try{
            try (FileOutputStream fos = new FileOutputStream("C:\\Users\\ray16\\OneDrive\\Documents\\STIS\\Semester_4\\PBO\\after_uts\\src\\responsi10\\database.dat"); 
                 ObjectOutputStream oos = new ObjectOutputStream(fos)) {
                oos.writeObject(instance);
            }
        } catch (FileNotFoundException ex) {
            System.err.println("File tidak ditemukan");
        } catch (IOException ex) {
            System.err.println("Gagal menulis file");
        }
    }
}
