// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class square extends rectangle {
	public square() {
		super();
	}

	public square(double side) {
		super(side, side);
	}

	public square(double side, String color, boolean filled) {
		super(side, side, color, filled);
	}

	public double getSide() {
		return getWidth();
	}

	public void setSide(double side) {
		setWidth(side);
		setLength(side);
	}

	public void setWidth(double side) {
		super.setWidth(side);
	}

	public void setLength(double side) {
		super.setLength(side);
	}

	public String toString() {
		return "Square[" + super.toString() + "]";
	}
}
