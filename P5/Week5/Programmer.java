// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

public class Programmer extends Pegawai {
  private String bahasaPemrograman;
  private String platform;

  public Programmer(String nama, LocalDate tanggalLahir, String NIP, String kantor, String unitKerja, String NIDN,
      String kelompokKeahlian, String bahasaPemrograman, String platform) {
    super(nama, tanggalLahir, NIP, kantor, unitKerja, NIDN, kelompokKeahlian);
    this.bahasaPemrograman = bahasaPemrograman;
    this.platform = platform;
  }

  public String getBahasaPemrograman() {
    return bahasaPemrograman;
  }

  public void setBahasaPemrograman(String bahasaPemrograman) {
    this.bahasaPemrograman = bahasaPemrograman;
  }

  public String getPlatform() {
    return platform;
  }

  public void setPlatform(String platform) {
    this.platform = platform;
  }

  public String toString() {
    return "Programmer[" + super.toString() + ", bahasaPemrograman = " + bahasaPemrograman + ", platform = " + platform
        + "]";
  }
}
