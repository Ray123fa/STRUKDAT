// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class AllTest {
	public static void main(String[] args) {
		Kendaraan motor = new Motor();
		motor.display();
		motor.jalanTol();
		motor._jalur();
		System.out.println();

		Kendaraan mobil = new Mobil();
		mobil.display();
		mobil.jalanTol();
		mobil._jalur();
		System.out.println();

		Kendaraan sepeda = new Sepeda();
		sepeda.display();
		sepeda.jalanTol();
		sepeda._jalur();
		System.out.println();

		Kendaraan orang = new Orang();
		orang.display();
		orang.jalanTol();
		orang._jalur();
		System.out.println();

		Kendaraan kapal = new Kapal();
		kapal.display();
		kapal.jalanTol();
		kapal._jalur();
		kapal.metal();
		System.out.println();

		Kendaraan pesawat = new Pesawat();
		pesawat.display();
		pesawat.jalanTol();
		pesawat._jalur();
		pesawat.metal();
		System.out.println();

		Kendaraan kereta = new Kereta();
		kereta.display();
		kereta.jalanTol();
		kereta._jalur();
		kereta.metal();
	}
}