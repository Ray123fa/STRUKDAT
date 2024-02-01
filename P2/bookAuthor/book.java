// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.lang.Override;
import java.util.Arrays;

class book {
	private String name;
	private author[] authors;
	private double price;
	private int qty;

	public book(String name, author[] authors, double price) {
		this.name = name;
		this.authors = authors;
		this.price = price;
		this.qty = 0;
	}

	public book(String name, author[] authors, double price, int qty) {
		this.name = name;
		this.authors = authors;
		this.price = price;
		this.qty = qty;
	}

	public String getName() {
		return name;
	}

	public author[] getAuthors() {
		return authors;
	}

	public double getPrice() {
		return price;
	}

	public void setPrice(double price) {
		this.price = price;
	}

	public int getQty() {
		return qty;
	}

	public void setQty(int qty) {
		this.qty = qty;
	}

	@Override
	public String toString() {
		return String.format("Book[name=%s, authors={%s}, price=%.2f, qty=%d]", name, Arrays.toString(authors), price, qty);
	}

	public String getAuthorNames() {
		String[] authorNames = new String[authors.length];
		for (int i = 0; i < authors.length; i++) {
			authorNames[i] = authors[i].getName();
		}
		return String.join(", ", authorNames);
	}
}
