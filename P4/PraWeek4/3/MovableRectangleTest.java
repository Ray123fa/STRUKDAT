// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class MovableRectangleTest {
	public static void main(String[] args) {
		// Move Left
		Movable m1 = new MovableRectangle(5, 6, 10, 15, 2, 2);
		System.out.println(m1);
		m1.moveLeft();
		System.out.println(m1);

		// Move Right
		System.out.println();
		Movable m2 = new MovableRectangle(2, 1, 2, 20, 3, 3);
		System.out.println(m2);
		m2.moveRight();
		System.out.println(m2);

		// Move Up
		System.out.println();
		Movable m3 = new MovableRectangle(3, 4, 5, 6, 4, 4);
		System.out.println(m3);
		m3.moveUp();
		System.out.println(m3);

		// Move Down
		System.out.println();
		Movable m4 = new MovableRectangle(1, 2, 3, 4, 5, 5);
		System.out.println(m4);
		m4.moveDown();
		System.out.println(m4);
	}
}
