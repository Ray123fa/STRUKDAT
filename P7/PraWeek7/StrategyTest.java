// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class StrategyTest {
	public static void main(String[] args) {
		Location kontrakanSari = new Location("Kontrakan Sari",
				new Coordinates(-6.122d, 106.101d));
		Location kontrakanNull = new Location("Kontrakan Null",
				new Coordinates(-6.252d, 106.912d));

		// Test Route
		Route ruteTerbaik = new Walking(kontrakanSari, kontrakanNull);
		ruteTerbaik.printRoute();

		// Ganti pakai rute motor
		ruteTerbaik = new Riding(kontrakanSari, kontrakanNull);
		ruteTerbaik.printRoute();

		// Ganti lagi pakai rute mobil
		ruteTerbaik = new Driving(kontrakanSari, kontrakanNull);
		ruteTerbaik.printRoute();

		// Sekarang kasus misal ada penambahan transportasi umum
		Routable Boarding = (a, b) -> {
			System.out.println("The implementaton of public transportation route goes here");
		};

		// Maka ruteTerbaik ttp bisa pakai
		ruteTerbaik.setUsedRoute(Boarding);
		ruteTerbaik.printRoute();

		/*
		 * Jadi prinsip dari OCP ttp terpakai karena saat menambah rute, tidak perlu
		 * mengedit
		 * Class route, tinggal buat sebuah kelas yang meng-implements Routable. Klo mau
		 * nambah
		 * class concrete juga bisa, bikin aja sebuah kelas yang meng-extends dari
		 * Route, misal
		 * PublicTransporting, ntar dalemnya ada method untuk mengcomposisi usedRoute
		 * dengan Boarding.
		 * Semenyenangkan itu, Darling~
		 */
	}
}
