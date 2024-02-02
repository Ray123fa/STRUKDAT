// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class testMyPoint {
	public static void main(String[] args) {
		MyPoint p1 = new MyPoint(); // (0,0)
		System.out.println("P1 -> " + p1.toString() + "\n");

		System.out.println("Set X = 8 dan Y = 6");
		p1.setX(8); // (8,0)
		System.out.println("P1 -> X: " + p1.getX());
		p1.setY(6); // (8,6)
		System.out.println("P1 -> Y: " + p1.getY());
		System.out.println("P1 -> " + p1.toString() + "\n");

		System.out.println("Set X = 3 dan Y = 5");
		p1.setXY(3, 5); // (3,5)
		System.out.println("P1 -> X: " + p1.getXY()[0]);
		System.out.println("P1 -> Y: " + p1.getXY()[1]);
		System.out.println("P1 -> " + p1.toString() + "\n");

		MyPoint p2 = new MyPoint(4, 9); // (4,9)
		System.out.println("P2 -> " + p2.toString());
		System.out.printf("Jarak P2 ke P1: %.2f\n", p2.distance(p1));
		System.out.printf("Jarak P2 ke (5, 6): %.2f\n", p2.distance(5, 6));
		System.out.printf("Jarak P2 ke (0, 0): %.2f\n", p2.distance());
	}
}