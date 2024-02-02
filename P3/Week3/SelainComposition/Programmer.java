// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Programmer extends Pegawai {
	private String lang;
	private String speacialize;
	private double lembur = 500000;

	Programmer() {
	}

	Programmer(String lang, String speacialize) {
		this.lang = lang;
		this.speacialize = speacialize;
	}

	Programmer(Pegawai pegawai, String lang, String speacialize) {
		super(
				pegawai.getNama(),
				pegawai.getTanggalLahir(),
				pegawai.getNIP(),
				pegawai.getNamaKantor(),
				pegawai.getUnitKerja());
		this.lang = lang;
		this.speacialize = speacialize;
	}

	public String getLang() {
		return lang;
	}

	public void setLang(String lang) {
		this.lang = lang;
	}

	public String getSpecialize() {
		return speacialize;
	}

	public void setSpecialize(String speacialize) {
		this.speacialize = speacialize;
	}

	public double getLembur() {
		return lembur;
	}

	public void setLembur(double lembur) {
		this.lembur = lembur;
	}

	@Override
	public String toString() {
		return ("Programmer[" +
				super.toString() +
				", BahasaPemrograman=" + lang +
				", Platform=" + speacialize +
				", Lembur=" + lembur +
				"]");
	}
}