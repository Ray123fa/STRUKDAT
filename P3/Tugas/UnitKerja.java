import java.util.List;

public class UnitKerja {
	private String unit;
	private List<Pegawai> daftarPegawai;

	public UnitKerja(String unit, List<Pegawai> daftarPegawai) {
		this.unit = unit;
		this.daftarPegawai = daftarPegawai;
	}

	public String getNama() {
		return unit;
	}

	public void setNama(String unit) {
		this.unit = unit;
	}

	public List<Pegawai> getDaftarPegawai() {
		return daftarPegawai;
	}
}
