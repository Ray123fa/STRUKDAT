// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Customer3 {
	private int id;
	private String name;
	private int discount;

	public Customer3(int id, String name, int discount) {
		this.id = id;
		this.name = name;
		this.discount = discount;
	}

	public int getID() {
		return this.id;
	}

	public String getName() {
		return this.name;
	}

	public int getDiscount() {
		return this.discount;
	}

	public void setDiscount(int discount) {
		this.discount = discount;
	}

	public String toString() {
		return this.name + "(" + this.id + ")" + "(" + this.discount + "%)";
	}
}
