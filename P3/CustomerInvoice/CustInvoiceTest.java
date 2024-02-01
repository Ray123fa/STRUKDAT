// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class CustInvoiceTest {
	public static void main(String[] args) {
		Customer3 c = new Customer3(1, "Rayhan", 10);
		System.out.println("ID: " + c.getID());
		System.out.println("Nama: " + c.getName());
		System.out.println("Diskon: " + c.getDiscount());
		System.out.println(c.toString() + "\n");

		Invoice i = new Invoice(1, c, 375000);
		System.out.println("ID: " + i.getID());
		System.out.println("Customer: " + i.getCustomer());
		System.out.println("Harga sebelum diskon: " + i.getAmount());
		System.out.println("Harga setelah diskon: " + i.getAmountAfterDiscount());
		System.out.println(i.toString());
	}
}
