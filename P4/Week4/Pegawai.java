// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

public class Pegawai extends Orang implements Dosen {
	private String NIP;
	private String kantor;
	private String unitKerja;
	private String alamat;
	private String NIDN;
	private String keahlian;

	Pegawai() {
	}

	Pegawai(String NIP, String kantor, String unitKerja) {
		this.NIP = NIP;
		this.kantor = kantor;
		this.unitKerja = unitKerja;
	}

	Pegawai(String nama, String NIP, String kantor, String unitKerja) {
		super(nama);
		this.NIP = NIP;
		this.kantor = kantor;
		this.unitKerja = unitKerja;
	}

	Pegawai(String nama, LocalDate tanggalLahir, String NIP, String kantor, String unitKerja) {
		super(nama, tanggalLahir);
		this.NIP = NIP;
		this.kantor = kantor;
		this.unitKerja = unitKerja;
	}

	public String getNIP() {
		return NIP;
	}

	public void setNIP(String NIP) {
		this.NIP = NIP;
	}

	public String getNamaKantor() {
		return kantor;
	}

	public void setNamaKantor(String kantor) {
		this.kantor = kantor;
	}

	public String getUnitKerja() {
		return unitKerja;
	}

	public void setUnitKerja(String unitKerja) {
		this.unitKerja = unitKerja;
	}

	public String getNama() {
		return super.getNama();
	}

	public void setNama(String nama) {
		super.setNama(nama);
	}

	@Override
	public String getAlamat() {
		return this.alamat;
	}

	@Override
	public void setAlamat(String alamat) {
		this.alamat = alamat;
	}

	@Override
	public String getNIDN() {
		return NIDN;
	}

	@Override
	public void setNIDN(String NIDN) {
		this.NIDN = NIDN;
	}

	@Override
	public String getKelompokKeahlian() {
		return keahlian;
	}

	@Override
	public void setKelompokKeahlian(String keahlian) {
		this.keahlian = keahlian;
	}

	@Override
	public String toString() {
		return "Pegawai[" +
				super.toString() +
				", NIP=" + NIP +
				", Kantor=" + kantor +
				", UnitKerja=" + unitKerja +
				", Alamat=" + alamat +
				", NIDN=" + NIDN +
				", Keahlian=" + keahlian +
				"]";
	}
}