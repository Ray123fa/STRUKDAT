// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

abstract class Orang {
	String nama;
	LocalDate tanggalLahir;

	Orang() {
	}

	Orang(String nama) {
		this.nama = nama;
	}

	Orang(String nama, LocalDate tanggalLahir) {
		this.nama = nama;
		this.tanggalLahir = tanggalLahir;
	}

	public String getNama() {
		return nama;
	}

	public void setNama(String nama) {
		this.nama = nama;
	}

	public LocalDate getTanggalLahir() {
		return tanggalLahir;
	}

	public void setTanggalLahir(LocalDate tanggalLahir) {
		this.tanggalLahir = tanggalLahir;
	}

	public String toString() {
		return "Orang[nama=" + nama + ", date=" + tanggalLahir + "]";
	}

	abstract public String getAlamat();

	abstract public void setAlamat(String alamat);
}