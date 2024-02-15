// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

public class AllTest {
	public static void main(String[] args) {
		// Create Pegawai Object
		Pegawai pegawai = new Pegawai("Ryoma Otsuka", LocalDate.of(2000, 12, 13), "12766", "Shinjuku", "IT", "13301",
				"Cyber Security");

		// Print pegawai
		System.out.println("Informasi Pegawai:");
		System.out.println(pegawai);

		// Set and get NIDN
		pegawai.setNIDN("13041");
		System.out.println("NIDN Pegawai: " + pegawai.getNIDN());

		// Set and get unit kerja
		pegawai.setUnitKerja("PSDM");
		System.out.println("Unit Kerja Pegawai: " + pegawai.getUnitKerja());

		// Print pekerjaan
		System.out.println("Pekerjaan Pegawai: " + pegawai.getPekerjaan());

		// Create Programmer Object
		Programmer programmer = new Programmer("Shandika Galih", LocalDate.of(1998, 6, 25), "15265", "Shinjuku", "IT",
				"12778", "Developer", "Golang", "Web");

		// Print programmer
		System.out.println("\nInformasi Programmer:");
		System.out.println(programmer);

		// Set and get Bahasa Pemrograman
		programmer.setBahasaPemrograman("C++");
		System.out.println("Bahasa Pemrograman Programmer: " + programmer.getBahasaPemrograman());

		// Set and get Platform
		programmer.setPlatform("Desktop");
		System.out.println("Platform Programmer: " + programmer.getPlatform());
	}
}