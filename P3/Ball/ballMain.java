// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class ballMain {
	public static void getterTest(Ball bola) {
		System.out.println("x is: " + bola.getX());
		System.out.println("y is: " + bola.getY());
		System.out.println("radius is: " + bola.getRadius());
		System.out.println("xDelta is: " + bola.getXDelta());
		System.out.println("yDelta is: " + bola.getYDelta() + "\n");
	}

	public static void main(String[] args) {
		Ball bola = new Ball(1.1f, 2.2f, 7, 3.3f, 4.4f);
		System.out.println(bola.toString() + "\n");

		// Test setter and getter
		bola.setX(50f);
		bola.setY(35f);
		bola.setRadius(10);
		bola.setXDelta(5f);
		bola.setYDelta(7f);
		System.out.println(bola.toString());
		getterTest(bola);

		// Test reflectHorizontal and reflectVertical
		bola.reflectHorizontal();
		System.out.println(bola.toString());
		bola.reflectVertical();
		System.out.println(bola.toString());
	}
}
