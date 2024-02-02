// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class NumberFive {
	public static void main(String[] args) {
		Cylinder c1 = new Cylinder();
		System.out.println(c1.toString());
		System.out.println("Radius: " + c1.getRadius());
		System.out.printf("Surface Area: %.2f\n", c1.getSurfaceArea());
		System.out.printf("Volume: %.2f\n", c1.getVolume());
		System.out.println();

		Cylinder c2 = new Cylinder(10.0);
		c2.setColor("navy");
		c2.setRadius(2.8);
		System.out.println(c2.toString());
		System.out.println("Radius: " + c2.getRadius());
		System.out.printf("Surface Area: %.2f\n", c2.getSurfaceArea());
		System.out.printf("Volume: %.2f\n", c2.getVolume());
		System.out.println();

		Cylinder c3 = new Cylinder(2.0, 8.0);
		c3.setColor("green");
		System.out.println(c3.toString());
		System.out.println("Radius: " + c3.getRadius());
		System.out.printf("Surface Area: %.2f\n", c3.getSurfaceArea());
		System.out.printf("Volume: %.2f\n", c3.getVolume());
		System.out.println();

		Cylinder c4 = new Cylinder(3.5, 12.0, "blue");
		System.out.println(c4.toString());
		System.out.println("Radius: " + c4.getRadius());
		System.out.printf("Surface Area: %.2f\n", c4.getSurfaceArea());
		System.out.printf("Volume: %.2f\n", c4.getVolume());
	}
}