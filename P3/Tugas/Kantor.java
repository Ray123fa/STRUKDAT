import java.time.LocalDate;

public class Kantor {
	public static void main(String[] args) {
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

		Pegawai pg1 = new Pegawai("Rayhan", LocalDate.of(2004, 2, 16), "222212766", "BPS Kota Banjarmasin", "Unit IT");
		pg1.setGaji(3500000);
		System.out.println(pg1.getNama() +
				", lahir pada " + pg1.getTanggalLahir() +
				", NIP: " + pg1.getNIP() +
				", kantor: " + pg1.getNamaKantor() +
				", bagian: " + pg1.getUnitKerja() +
				", dan gajinya " + pg1.getGaji());
	}
}
