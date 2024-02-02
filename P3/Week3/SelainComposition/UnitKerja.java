// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.util.ArrayList;
import java.util.List;

public class UnitKerja {
	private String nama;
	private List<Pegawai> daftarPegawai = new ArrayList<Pegawai>();

	UnitKerja(String nama, List<Pegawai> daftarPegawai) {
		this.nama = nama;
		this.daftarPegawai = daftarPegawai;
	}

	public String getNama() {
		return nama;
	}

	public List<Pegawai> getDaftarPegawai() {
		return daftarPegawai;
	}

	public List<Pegawai> getPegawaiByUnit(String unit) {
		List<Pegawai> pegawaiByUnit = new ArrayList<Pegawai>();
		for (Pegawai pegawai : daftarPegawai) {
			if (pegawai.getUnitKerja().equals(unit)) {
				pegawaiByUnit.add(pegawai);
			}
		}
		return pegawaiByUnit;
	}

	public void addPegawai(Pegawai pegawai) {
		daftarPegawai.add(pegawai);
	}

	public void alihUnit(Pegawai pegawai, UnitKerja unitTujuan) {
		if (daftarPegawai.contains(pegawai)) {
			daftarPegawai.remove(pegawai);
			unitTujuan.addPegawai(pegawai);
			pegawai.setUnitKerja(unitTujuan.getNama());
			System.out.println(pegawai.getNama() + " dipindahkan dari " + nama + " ke " + unitTujuan.getNama());
		} else {
			System.out.println(pegawai.getNama() + " tidak terdaftar di " + nama);
		}
	}

	public String toString() {
		return "UnitKerja{" + "nama='" + nama + '\'' + ", daftarPegawai=" + getPegawaiByUnit(nama) + '}';
	}

	public static void printAllUnits(UnitKerja... units) {
		for (UnitKerja unit : units) {
			System.out.println(unit.toString());
		}
	}
}