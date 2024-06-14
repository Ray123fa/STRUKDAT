/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this
 * license Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package latihanserver;

import java.io.Serializable;

/**
 *
 * @author Muhammad Rayhan Faridh
 */
public class Pesan implements Serializable {
    private String nama;
    private String pesan;

    public Pesan(String nama, String pesan) {
        this.nama = nama;
        this.pesan = pesan;
    }

    @Override
    public String toString() {
        return "[" + nama + "]" + pesan;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public String getPesan() {
        return pesan;
    }

    public void setPesan(String pesan) {
        this.pesan = pesan;
    }
}
