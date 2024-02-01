// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.lang.Math;

public class MyPoint {
	private int x;
	private int y;

	public MyPoint() {
		this.x = 0;
		this.y = 0;
	}

	public MyPoint(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public int getX() {
		return this.x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return this.y;
	}

	public void setY(int y) {
		this.y = y;
	}

	// Kembalikan nilai x dan y dalam bentuk array
	public int[] getXY() {
		int[] xy = { this.x, this.y };
		return xy;
	}

	// Atur nilai x dan y
	public void setXY(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}

	// Kembalikan jarak dari titik ini ke titik (x, y)
	public double distance(int x, int y) {
		int xDiff = this.x - x;
		int yDiff = this.y - y;
		return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
	}

	// Kembalikan jarak dari titik ini ke titik (anotherX, anotherY)
	public double distance(MyPoint another) {
		int xDiff = this.x - another.getX();
		int yDiff = this.y - another.getY();
		return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
	}

	// Kembalikan jarak dari titik ini ke titik (0, 0)
	public double distance() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
}