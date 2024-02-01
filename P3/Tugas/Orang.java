import java.time.LocalDate;

public class Orang {
	private String nama;
	private LocalDate tanggalLahir;

	public Orang() {
		this(null, null);
	}

	public Orang(String nama) {
		this.nama = nama;
	}

	public Orang(String nama, LocalDate tanggalLahir) {
		this.nama = nama;
		this.tanggalLahir = tanggalLahir;
	}

	public String getNama() {
		return nama;
	}

	public void setNama(String nama) {
		this.nama = nama;
	}

	public LocalDate getTanggalLahir() {
		return tanggalLahir;
	}

	public void setTanggalLahir(LocalDate tanggalLahir) {
		this.tanggalLahir = tanggalLahir;
	}

	public double getGaji() {
		return 0;
	}
}