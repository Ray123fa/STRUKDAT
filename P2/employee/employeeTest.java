// Muhammad Rayhan Faridh
// 222212766
// 2KS1

// To test employee.java

public class employeeTest {
	static void show(employee e, int percent) {
		System.out.println(e.toString());
		System.out.println("ID: " + e.getID());
		System.out.println("Name: " + e.getName());
		System.out.println("Salary: " + e.getSalary());
		System.out.println("Annual Salary (before raising): " + e.getAnnualSalary());

		System.out.println("Raise Salary: " + e.raiseSalary(percent));
		System.out.println("Annual Salary (after raising): " + e.getAnnualSalary() + "\n");
	}

	public static void main(String[] args) {
		employee e1 = new employee(1, "Muhammad", "Rayhan", 750000);
		show(e1, 10);

		employee e2 = new employee(2, "Faridh", "Rayhan", 2500000);
		show(e2, 15);

		employee e3 = new employee(3, "Muhammad", "Faridh", 500000);
		show(e3, 5);
	}
}
