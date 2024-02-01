// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class rectangle extends shape {
	private double width;
	private double length;

	public rectangle() {
		super();
		width = 1.0;
		length = 1.0;
	}

	public rectangle(double width, double length) {
		super();
		this.width = width;
		this.length = length;
	}

	public rectangle(double width, double length, String color, boolean filled) {
		super(color, filled);
		this.width = width;
		this.length = length;
	}

	public double getWidth() {
		return width;
	}

	public void setWidth(double width) {
		this.width = width;
	}

	public double getLength() {
		return length;
	}

	public void setLength(double length) {
		this.length = length;
	}

	public double getArea() {
		return width * length;
	}

	public double getPerimeter() {
		return 2.0 * (width + length);
	}

	public String toString() {
		return "Rectangle[" + super.toString() + ",width=" + width + ",length=" + length + "]";
	}
}
