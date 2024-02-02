import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Kantor {
	public static void main(String[] args) {
		List<Pegawai> daftarPegawai = new ArrayList<Pegawai>();
		UnitKerja unitIT = new UnitKerja("Unit IT", daftarPegawai);
		UnitKerja unitKeuangan = new UnitKerja("Keuangan", daftarPegawai);

		Orang rayhan = new Orang();
		rayhan.setNama("Rayhan");
		rayhan.setTanggalLahir(LocalDate.of(2004, 2, 16));

		Orang bella = new Orang("Bella");
		bella.setTanggalLahir(LocalDate.of(2005, 10, 24));

		System.out.println("Ada orang:");
		System.out.println(rayhan.getNama() +
				", lahir pada " + rayhan.getTanggalLahir() +
				", dan gajinya " + rayhan.getGaji());
		System.out.println(bella.getNama() +
				", lahir pada " + bella.getTanggalLahir() +
				", dan gajinya " + bella.getGaji() + "\n");

		Pegawai pegawai1 = new Pegawai("Rayhan", LocalDate.of(2004, 2, 16), "222212766", "BPS Kota Banjarmasin", "Unit IT");
		pegawai1.setGaji(3500000);
		daftarPegawai.add(pegawai1);

		Pegawai pegawai2 = new Pegawai("Nisa", LocalDate.of(2005, 10, 24), "222313301", "BPS Kota Banjarmasin",
				"Keuangan");
		pegawai2.setGaji(3000000);
		daftarPegawai.add(pegawai2);

		System.out.println("Daftar pegawai di " + unitIT.getUnit() + ":");
		for (Pegawai pegawai : unitIT.getDaftarPegawai()) {
			System.out.println(pegawai.getNama() +
					", lahir pada " + pegawai.getTanggalLahir() +
					", NIP: " + pegawai.getNIP() +
					", kantor: " + pegawai.getNamaKantor() +
					", bagian: " + pegawai.getUnitKerja() +
					", dan gajinya " + pegawai.getGaji());
		}
	}
}
