// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.sql.Date;

public class AllTest {
	public static void main(String[] args) {
		// Membuat objek Pegawai
		Pegawai pegawai = new Pegawai("Kuroko Tetsuya", Date.valueOf("1998-09-09"), "123456", "Seirin", "IT", "987654",
				"Cyber Security");

		// Mencetak informasi pegawai
		System.out.println("\nInformasi Pegawai:");
		System.out.println(pegawai);

		// Mengatur dan mencetak NIDN pegawai
		pegawai.setNIDN("999999");
		System.out.println("NIDN Pegawai: " + pegawai.getNIDN());

		// Mengatur dan mencetak unit kerja pegawai
		pegawai.setUnitKerja("Humas");
		System.out.println("Unit Kerja Pegawai: " + pegawai.getUnitKerja());

		// Mencetak pekerjaan pegawai
		System.out.println("Pekerjaan Pegawai: " + pegawai.getPekerjaan());

		// Membuat objek Programmer
		Programmer programmer = new Programmer("Kagami", Date.valueOf("1998-06-25"), "654321", "Seirin", "IT", "888888",
				"Developer", "Javascript", "Web");

		// Mencetak informasi programmer
		System.out.println("\nInformasi Programmer:");
		System.out.println(programmer);

		// Mengatur dan mencetak bahasa pemrograman programmer
		programmer.setBahasaPemrograman("Python");
		System.out.println("Bahasa Pemrograman Programmer: " + programmer.getBahasaPemrograman());

		// Mengatur dan mencetak platform programmer
		programmer.setPlatform("Desktop");
		System.out.println("Platform Programmer: " + programmer.getPlatform());
	}
}
