// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public abstract class WarnaiPakaian implements Pakaian {
	protected Pakaian warnai;

	public WarnaiPakaian(Pakaian warnai) {
		this.warnai = warnai;
	}

	@Override
	public void pakai() {
		warnai.pakai();
	}
}