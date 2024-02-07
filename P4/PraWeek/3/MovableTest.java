// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class MovableTest {
	public static void main(String[] args) {
		// Move Left
		Movable m1 = new MovablePoint(5, 6, 10, 15);
		System.out.println(m1);
		m1.moveLeft();
		System.out.println(m1);

		// Move Right
		System.out.println();
		Movable m2 = new MovableCircle(2, 1, 2, 20, 3);
		System.out.println(m2);
		m2.moveRight();
		System.out.println(m2);

		// Move Up
		System.out.println();
		Movable m3 = new MovablePoint(3, 4, 5, 6);
		System.out.println(m3);
		m3.moveUp();
		System.out.println(m3);

		// Move Down
		System.out.println();
		Movable m4 = new MovableCircle(1, 2, 3, 4, 5);
		System.out.println(m4);
		m4.moveDown();
		System.out.println(m4);
	}
}