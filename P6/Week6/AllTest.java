// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.util.GregorianCalendar;

public class AllTest {
	public static void main(String[] args) {
		Pegawai rayfa = new Pegawai(
				"Rayfa", new GregorianCalendar(2004, 1, 16),
				"12766", "Polstat STIS", "Unit IT",
				"092504", "Ngoding");
		System.out.println(
				"Object Pegawai:\nNama: " + rayfa.getNama() +
						"\nNama Panggilan: " + rayfa.getNamaPanggilan() +
						"\nNIP: " + rayfa.getNIP() +
						"\nKantor: " + rayfa.getKantor() +
						"\nPekerjaan: " + rayfa.getPekerjaan() +
						"\nTanggal Lahir: " + rayfa.getTanggalLahir());

		Pegawai itsme = new Pegawai(
				"Itsme", "13301", "Polstat STIS",
				"BAU", "0040925", "Ngoding");
		System.out.println(
				"\nObject Pegawai:\nNama: " + itsme.getNama() +
						"\nNama Panggilan: " + itsme.getNamaPanggilan() +
						"\nNIP: " + itsme.getNIP() +
						"\nKantor: " + itsme.getKantor() +
						"\nPekerjaan: " + itsme.getPekerjaan() +
						"\nTanggal Lahir: " + itsme.getTanggalLahir());

		Programmer faridh = new Programmer(
				"Faridh", new GregorianCalendar(2004, 1, 16),
				"12776", "Polstat STIS", "Unit IT",
				"092404", "Ngoding",
				"Java", "Python");
		System.out.println(
				"\nObject Programmer:\nNama: " + faridh.getNama() +
						"\nNama Panggilan: " + faridh.getNamaPanggilan() +
						"\nNIP: " + faridh.getNIP() +
						"\nKantor: " + faridh.getKantor() +
						"\nPekerjaan: " + faridh.getPekerjaan() +
						"\nTanggal Lahir: " + faridh.getTanggalLahir() +
						"\nBahasa Pemrograman: " + faridh.getBahasaPemrograman());
	}
}