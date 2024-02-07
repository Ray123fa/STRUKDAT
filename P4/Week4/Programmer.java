// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Programmer extends Pegawai {
	private String bahasaPemrograman;
	private String platform;

	Programmer() {
	}

	Programmer(String bahasaPemrograman, String platform) {
		this.bahasaPemrograman = bahasaPemrograman;
		this.platform = platform;
	}

	Programmer(Pegawai pegawai, String bahasaPemrograman, String platform) {
		super(
				pegawai.getNama(),
				pegawai.getTanggalLahir(),
				pegawai.getNIP(),
				pegawai.getNamaKantor(),
				pegawai.getUnitKerja());
		this.bahasaPemrograman = bahasaPemrograman;
		this.platform = platform;
	}

	public String getLang() {
		return bahasaPemrograman;
	}

	public void setLang(String bahasaPemrograman) {
		this.bahasaPemrograman = bahasaPemrograman;
	}

	public String getSpecialize() {
		return platform;
	}

	public void setSpecialize(String platform) {
		this.platform = platform;
	}

	@Override
	public String toString() {
		return ("Programmer[" +
				super.toString() +
				", BahasaPemrograman=" + bahasaPemrograman +
				", Platform=" + platform +
				"]");
	}
}