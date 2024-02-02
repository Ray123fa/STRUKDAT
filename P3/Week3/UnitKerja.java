import java.util.List;

public class UnitKerja {
	private String unit;
	private List<Pegawai> daftarPegawai;

	public UnitKerja(String unit, List<Pegawai> daftarPegawai) {
		this.unit = unit;
		this.daftarPegawai = daftarPegawai;
	}

	public String getUnit() {
		return unit;
	}

	public void setUnit(String unit) {
		this.unit = unit;
	}

	public List<Pegawai> getDaftarPegawai() {
		return daftarPegawai;
	}
}
