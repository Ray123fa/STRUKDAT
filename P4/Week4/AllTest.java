// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

public class AllTest {
	public static void main(String[] args) {
		// Test Orang
		// Orang o = new Orang("Rayhan", LocalDate.of(2004, 2, 16));
		// Error karena Orang merupakan kelas abstrak

		// Test Pegawai
		Pegawai lutfi = new Pegawai();
		lutfi.setNama("Lutfi");
		lutfi.setAlamat("Otista 64 C");
		System.out.printf("Alamat %s: %s\n", lutfi.getNama(), lutfi.getAlamat());

		// Test Implement Dosen
		System.out.println();
		Pegawai rayfa = new Pegawai("Rayfa", LocalDate.of(2004, 2, 16), "16040386", "BPS Kota Banjarmasin", "IT");
		rayfa.setAlamat("Jl. Martapura Lama");
		rayfa.setNIDN("1404038602");
		rayfa.setKelompokKeahlian("Web Programming");
		System.out.println(rayfa.toString());

		// Test Programmer
		System.out.println();
		Pegawai r = new Pegawai("Rayhan", LocalDate.of(2004, 2, 16), "222212766", "STIS", "IT");
		Programmer rayhan = new Programmer(r, "PHP", "Web");
		rayhan.setAlamat("Jl. Hasbi");
		System.out.println(rayhan.toString());
	}
}