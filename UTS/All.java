// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.util.List;

class All {
	abstract class Shape {
		private String color;

		public void draw() {
			System.out.println("Drawing a shape");
		}

		public String getColor() {
			return color;
		}

		public void setColor(String color) {
			this.color = color;
		}
	}

	public class Point {
		private double x;
		private double y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}

	public class Rectangle extends Shape {
		private double width;
		private double height;

		public Rectangle(double width, double height) {
			this.width = width;
			this.height = height;
		}

		public void draw() {
			System.out.println("Drawing a rectangle");
		}
	}

	public class Circle extends Shape {
		private double radius;

		public Circle(double radius) {
			this.radius = radius;
		}

		public void draw() {
			System.out.println("Drawing a circle");
		}
	}

	public class Polygon extends Shape {
		private List<Point> vertices;

		public Polygon(List<Point> vertices) {
			this.vertices = vertices;
		}

		public void draw() {
			System.out.println("Drawing a polygon");
		}
	}

	public class Drawing {
		public List<Shape> shapes;

		public Drawing(List<Shape> shapes) {
			this.shapes = shapes;
		}

		public void addShape(Shape shape) {
			shapes.add(shape);
		}

		public void draw() {
			for (Shape shape : shapes) {
				shape.draw();
			}
		}
	}

	public static void main(String[] args) {
		All all = new All();
		Rectangle rectangle = all.new Rectangle(5, 10);
		Circle circle = all.new Circle(5);
		Polygon polygon =
				all.new Polygon(List.of(all.new Point(0, 0), all.new Point(1, 1), all.new Point(2, 2)));
		Drawing drawing = all.new Drawing(List.of(rectangle, circle, polygon));

		System.out.println("Menampilkan shape satu per satu:");
		rectangle.draw();
		circle.draw();
		polygon.draw();

		System.out.println("\nMenampilkan semua shape yang ada pada list:");
		drawing.draw();

		System.out.println("\nMenampilkan warna dari masing-masing shape:");
		rectangle.setColor("red");
		circle.setColor("green");
		polygon.setColor("blue");

		System.out.println("Rectangle color: " + rectangle.getColor());
		System.out.println("Circle color: " + circle.getColor());
		System.out.println("Polygon color: " + polygon.getColor());
	}
}
