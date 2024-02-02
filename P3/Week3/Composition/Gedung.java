// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.util.List;
import java.util.ArrayList;

public class Gedung {
	private List<Ruang> daftarRuang = new ArrayList<Ruang>();

	Gedung() {
		Ruang ruang = new Ruang("Utama");
		daftarRuang.add(ruang);
	}

	public void addRuang(String namaRuang) {
		Ruang ruang = new Ruang(namaRuang);
		daftarRuang.add(ruang);
	}

	public List<Ruang> getDaftarRuang() {
		return daftarRuang;
	}
}