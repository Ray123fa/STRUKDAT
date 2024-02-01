// Muhammad Rayhan Faridh
// 222212766
// 2KS1

// To test account.java

class accountTest {
	static void show(account a) {
		System.out.println(a.toString());
	}

	static void pemasukan(account a, int amount) {
		a.credit(amount);
		System.out.println("\nPemasukan " + amount + " ke " + a.getName());
		show(a);
	}

	static void pengeluaran(account a, int amount) {
		a.debit(amount);
		System.out.println("\nPengeluaran " + amount + " dari " + a.getName());
		show(a);
	}

	public static void main(String[] args) {
		account a1 = new account("A001", "Rayhan", 500000);
		account a2 = new account("A002", "Faridh", 350000);

		System.out.println("Saldo awal:");
		show(a1);
		show(a2);

		pemasukan(a1, 100000);
		pengeluaran(a2, 50000);

		System.out.println("\nTransfer 20000 dari " + a1.getName() + " ke " + a2.getName());
		a1.transferTo(a2, 20000);
		show(a1);
		show(a2);
	}
}