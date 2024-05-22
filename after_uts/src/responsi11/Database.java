/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package responsi11;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.sql.*;
import java.util.Arrays;
import javax.swing.JOptionPane;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Database implements Serializable{
    public static Database instance;
    private boolean login = false;
    
    private final String DB_TYPE = "mysql";
    private final String DB_HOST = "localhost";
    private final String DB_PORT = "3306";
    private final String DB_NAME = "pbo";
    private final String DB_USER = "root";
    private final String DB_PASS = "root";

    private Database(){}

    public static synchronized Database getInstance(){
        if(instance == null){
            instance = new Database();
        }
        
        return instance;
    }
    
    public boolean isLogin(){
        return login;
    }
    
    public void setLogin(boolean login){
        this.login = login;
    }
    
    public void insertMahasiswa(Mahasiswa mahasiswa) throws SQLException{
        Connection conn = getConnection();
        try{
            String sql = "INSERT INTO mahasiswa VALUES (?,?,?,?,?,?,?)";
            PreparedStatement pstmt = conn.prepareStatement(sql);
            pstmt.setString(1, mahasiswa.getNim());
            pstmt.setString(2, mahasiswa.getNama());
            pstmt.setString(3, mahasiswa.getJenisKelamin());
            pstmt.setInt(4, mahasiswa.getUmur());
            pstmt.setString(5, mahasiswa.getAlamat());
            pstmt.setString(6, mahasiswa.getProvinsi());
            pstmt.setString(7, String.join(",", mahasiswa.getHobi()));
            pstmt.executeUpdate();
        }catch(SQLException ex){
            throw ex;
        }finally{
            if(conn != null){
                conn.close();
            }
        }
    }
    
    public void deleteMahasiswa(String nim) throws SQLException{
        Connection conn = getConnection();
        try{
            String sql = "DELETE FROM mahasiswa WHERE nim = '" + nim + "'";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);
        } catch(SQLException ex){
            JOptionPane.showMessageDialog(null, ex);
        }       
    }
    
    public void updateMahasiswa(Mahasiswa mahasiswa) throws SQLException{
        Connection conn = getConnection();
        try{
            String sql = "UPDATE mahasiswa " +
                         "SET nim = '" + mahasiswa.getNim() + "', " +
                             "nama = '" + mahasiswa.getNama() + "', " +
                             "jenis_kelamin = '" + mahasiswa.getJenisKelamin() + "', " +
                             "umur = " + mahasiswa.getUmur() + ", " +
                             "alamat = '" + mahasiswa.getAlamat() + "', " +
                             "provinsi = '" + mahasiswa.getProvinsi() + "', " +
                             "hobi = '" + String.join(",", mahasiswa.getHobi()) + "' " + 
                          "WHERE nim = '" + mahasiswa.getNim() + "' ";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sql);
        } catch (SQLException ex){
            System.err.println(ex);
            JOptionPane.showMessageDialog(null, ex);
        }
    }
    
    public List<Mahasiswa> getListMahasiswa() throws SQLException{
        List<Mahasiswa> mhsList = new ArrayList<>();
        Connection conn = getConnection();
        try {
            String sql = "SELECT * FROM mahasiswa";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(sql);

            while (rs.next()) {
                Mahasiswa mhs = new Mahasiswa();
                mhs.setNim(rs.getString("nim"));
                mhs.setNama(rs.getString("nama"));
                mhs.setJenisKelamin(rs.getString("jenis_kelamin"));
                mhs.setUmur(rs.getInt("umur"));
                mhs.setAlamat(rs.getString("alamat"));
                mhs.setProvinsi(rs.getString("provinsi"));
                mhs.setHobi(new ArrayList<>(Arrays.asList(rs.getString("hobi").split(","))));
                mhsList.add(mhs);
            }

        } catch (SQLException ex) {
            throw ex;
        } finally{
            if(conn != null){
                conn.close();
            }
        }

        return mhsList;
    }
    
    private Connection getConnection() throws SQLException{
        return DriverManager.getConnection("jdbc:"+DB_TYPE+"://"+DB_HOST+":"+DB_PORT+"/"+DB_NAME, 
        DB_USER, DB_PASS);
    }
}
