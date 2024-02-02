// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;
import java.util.List;
import java.util.ArrayList;

public class Kantor {
	public static void main(String[] args) {
		List<Pegawai> daftarPegawai = new ArrayList<Pegawai>();
		UnitKerja IT = new UnitKerja("IT", daftarPegawai);
		UnitKerja Keu = new UnitKerja("Keuangan", daftarPegawai);

		Orang rayhan = new Orang();
		rayhan.setNama("Rayhan");
		rayhan.setTanggalLahir(LocalDate.of(2004, 2, 16));

		Orang bella = new Orang("Bella");
		bella.setTanggalLahir(LocalDate.of(2005, 10, 24));

		System.out.println("Orang:");
		System.out.println(
				rayhan.getNama() + " lahir pada " + rayhan.getTanggalLahir() + ", gaji: " + rayhan.getGaji());
		System.out.println(
				bella.getNama() + " lahir pada " + bella.getTanggalLahir() + ", gaji: " + bella.getGaji() + "\n");

		Programmer rayfa = new Programmer(new Pegawai(
				"Rayfa",
				LocalDate.of(2004, 2, 16),
				"222212766",
				"STIS",
				"IT"),
				"PHP",
				"Web Application");
		IT.addPegawai(rayfa);

		Pegawai tuti = new Pegawai(
				"Tuti",
				LocalDate.of(1997, 8, 2),
				"6836492379",
				"STIS",
				"IT");
		IT.addPegawai(tuti);
		IT.alihUnit(tuti, Keu); // Tuti beralih unit dari IT ke Keuangan

		Pegawai nisa = new Pegawai(
				"Nisa",
				LocalDate.of(2005, 10, 24),
				"222313301",
				"STIS",
				"Keuangan");
		Keu.addPegawai(nisa);
		Keu.alihUnit(nisa, IT); // Nisa beralih unit dari Keuangan ke IT

		System.out.println("\nPegawai IT:");
		IT.getPegawaiByUnit("IT").forEach(pegawai -> System.out.println(pegawai.toString()));

		System.out.println("\nPegawai Keuangan:");
		Keu.getPegawaiByUnit("Keuangan").forEach(pegawai -> System.out.println(pegawai.toString()));

		System.out.println("\nSeluruh Unit:");
		UnitKerja.printAllUnits(IT, Keu);
	}
}