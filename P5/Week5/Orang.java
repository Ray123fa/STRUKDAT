// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.sql.Date;

public abstract class Orang {
  private String nama;
  private Date tanggalLahir;

  public Orang(String nama, Date tanggalLahir) {
    this.nama = nama;
    this.tanggalLahir = tanggalLahir;
  }

  public String getNama() {
    return nama;
  }

  public void setNama(String nama) {
    this.nama = nama;
  }

  public Date getTanggalLahir() {
    return tanggalLahir;
  }

  public void setTanggalLahir(Date tanggalLahir) {
    this.tanggalLahir = tanggalLahir;
  }

  public String toString() {
    return "Orang[nama = " + nama + ", tanggalLahir = " + tanggalLahir + "]";
  }

  public String getNamaPanggilan() {
    String[] arrNama = nama.split(" ", 4);
    return arrNama[0] + " " + arrNama[1] + " " + arrNama[2];
  }
}
