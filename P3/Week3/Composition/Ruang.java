// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Ruang {
	private String namaRuang;

	Ruang(String namaRuang) {
		this.namaRuang = namaRuang;
	}

	public String getNamaRuang() {
		return namaRuang;
	}

	public void setNamaRuang(String namaRuang) {
		this.namaRuang = namaRuang;
	}

	public String toString() {
		return "Ruang " + namaRuang;
	}
}
