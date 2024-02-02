// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;
import java.lang.Override;

public class Pegawai extends Orang {
	private String NIP;
	private String namaKantor;
	private String unitKerja;
	private double gaji = 7000000;

	Pegawai() {
	}

	Pegawai(String NIP, String namaKantor, String unitKerja) {
		this.NIP = NIP;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	Pegawai(String nama, String NIP, String namaKantor, String unitKerja) {
		super(nama);
		this.NIP = NIP;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	Pegawai(String nama, LocalDate tanggalLahir, String NIP, String namaKantor, String unitKerja) {
		super(nama, tanggalLahir);
		this.NIP = NIP;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	public String getNIP() {
		return NIP;
	}

	public void setNIP(String NIP) {
		this.NIP = NIP;
	}

	public String getNamaKantor() {
		return namaKantor;
	}

	public void setNamaKantor(String namaKantor) {
		this.namaKantor = namaKantor;
	}

	public String getUnitKerja() {
		return unitKerja;
	}

	public void setUnitKerja(String unitKerja) {
		this.unitKerja = unitKerja;
	}

	public double getGaji() {
		return gaji;
	}

	public void setGaji(double gaji) {
		this.gaji = gaji;
	}

	@Override
	public String toString() {
		return ("Pegawai[" +
				super.toString() +
				", NIP=" + NIP +
				", NamaKantor=" + namaKantor +
				", UnitKerja=" + unitKerja +
				", Gaji=" + gaji +
				"]");
	}
}