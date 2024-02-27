// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Orang extends Kendaraan {
	public Orang() {
		freeway = new Can();
		jalur = new Darat();
	}

	public void display() {
		System.out.println("Bisa memiliki roda(kursi roda, sepatu roda) atau tidak beroda");
	}
}