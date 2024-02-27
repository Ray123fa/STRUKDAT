// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public abstract class Kendaraan {
	Freeway freeway;
	Jalur jalur;

	public abstract void display();

	public void jalanTol() {
		freeway.able();
	}

	public void _jalur() {
		jalur.elemen();
	}

	public void metal() {
		System.out.println("Made with metal");
	}
}