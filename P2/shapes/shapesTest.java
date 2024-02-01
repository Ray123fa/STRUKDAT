// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class shapesTest {
	static void testShape(shape s) {
		System.out.println(s.toString());
		System.out.println("Color : " + s.getColor());
		System.out.println("Filled: " + s.isFilled());
		System.out.println();
	}

	static void testCircle(circle c) {
		System.out.println(c.toString());
		System.out.println("Color    : " + c.getColor());
		System.out.println("Filled   : " + c.isFilled());
		System.out.println("Radius   : " + c.getRadius());
		System.out.printf("Area     : %.2f\n", c.getArea());
		System.out.printf("Perimeter: %.2f\n", c.getPerimeter());
		System.out.println();
	}

	static void testRectangle(rectangle r) {
		System.out.println(r.toString());
		System.out.println("Color    : " + r.getColor());
		System.out.println("Filled   : " + r.isFilled());
		System.out.println("Width    : " + r.getWidth());
		System.out.println("Length   : " + r.getLength());
		System.out.println("Area     : " + r.getArea());
		System.out.println("Perimeter: " + r.getPerimeter());
		System.out.println();
	}

	static void testSquare(square s) {
		System.out.println(s.toString());
		System.out.println("Color    : " + s.getColor());
		System.out.println("Filled   : " + s.isFilled());
		System.out.println("Side     : " + s.getSide());
		System.out.println("Area     : " + s.getArea());
		System.out.println("Perimeter: " + s.getPerimeter());
		System.out.println();
	}

	public static void main(String[] args) {
		// Test shape
		shape s1 = new shape("blue", true);
		testShape(s1);

		// Test circle
		circle c1 = new circle(5, "green", false);
		c1.setRadius(7);
		c1.setColor("red");
		testCircle(c1);

		// Test rectangle
		rectangle r1 = new rectangle(3, 4, "yellow", true);
		r1.setWidth(5);
		r1.setLength(6);
		testRectangle(r1);

		// Test square
		square sq1 = new square(5, "purple", false);
		sq1.setSide(7);
		sq1.setFilled(true);
		testSquare(sq1);
	}
}
