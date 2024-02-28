// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Customer implements Observer {
	private Observable observable;
	private String username;

	public Customer(Observable observable, String username) {
		this.observable = observable;
		this.username = username;
	}

	@Override
	public void update() {
		System.out.println("Buku Pink Tersedia");
		buyDress();
	}

	private void buyDress() {
		System.out.println(username + " menambahkan Buku Pink.");
	}

	public void unsubscribe() {
		observable.removeObserver(this);
	}
}
