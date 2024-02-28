// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class PegawaiFactory {
	public Pegawai buatPegawai(String nama, String tipe) {
		switch (tipe) {
			case "tetap":
				return new PegawaiTetap(nama);
			case "kontrak":
				return new PegawaiKontrak(nama);
			default:
				return null;
		}
	}
}