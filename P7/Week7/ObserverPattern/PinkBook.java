// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.util.ArrayList;

public class PinkBook implements Observable {
	private boolean inStock = true;
	private ArrayList<Observer> customers;

	public PinkBook(boolean inStock) {
		this.inStock = inStock;
		customers = new ArrayList<>();
	}

	public boolean isInStock() {
		return inStock;
	}

	public void setInStock(boolean inStock) {
		this.inStock = inStock;
	}

	@Override
	public void addObserver(Observer O) {
		customers.add(O);
	}

	@Override
	public void removeObserver(Observer O) {
		customers.remove(O);
	}

	@Override
	public void notifyObserver() {
		for (int i = 0; i < customers.size(); i++) {
			customers.get(i).update();
		}
	}
}
