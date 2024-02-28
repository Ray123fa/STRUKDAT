// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class FactoryPatternMain {
	public static void main(String[] args) {
		PegawaiFactory factory = new PegawaiFactory();
		System.out.println(factory.buatPegawai("Lutfi", "tetap").toString());

		System.out.println();
		System.out.println(factory.buatPegawai("Dani", "kontrak").toString());
	}
}