// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.lang.Math;

public class circle extends shape {
	private double radius;

	public circle() {
		super();
		radius = 1.0;
	}

	public circle(double radius) {
		super();
		this.radius = radius;
	}

	public circle(double radius, String color, boolean filled) {
		super(color, filled);
		this.radius = radius;
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	public double getArea() {
		return radius * radius * Math.PI;
	}

	public double getPerimeter() {
		return 2.0 * radius * Math.PI;
	}

	public String toString() {
		return "Circle[" + super.toString() + ",radius=" + radius + "]";
	}
}
