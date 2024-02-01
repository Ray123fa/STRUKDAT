import java.time.LocalDate;

public class Pegawai extends Orang {
	private String nip;
	private String namaKantor;
	private String unitKerja;
	private double gaji;

	public Pegawai() {
		this(null, null, null, null, null);
	}

	public Pegawai(String nip, String namaKantor, String unitKerja) {
		this.nip = nip;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	public Pegawai(String nama, String nip, String namaKantor, String unitKerja) {
		super(nama);
		this.nip = nip;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	public Pegawai(String nama, LocalDate tanggalLahir, String nip, String namaKantor, String unitKerja) {
		super(nama, tanggalLahir);
		this.nip = nip;
		this.namaKantor = namaKantor;
		this.unitKerja = unitKerja;
	}

	public String getNIP() {
		return nip;
	}

	public void setNIP(String nip) {
		this.nip = nip;
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
}