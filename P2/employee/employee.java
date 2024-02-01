// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class employee {
	private int id;
	private String firstname;
	private String lastname;
	private int salary;

	public employee(int id, String fname, String lname, int salary) {
		this.id = id;
		this.firstname = fname;
		this.lastname = lname;
		this.salary = salary;
	}

	public int getID() {
		return id;
	}

	public String getFirstName() {
		return firstname;
	}

	public String getLastName() {
		return lastname;
	}

	public String getName() {
		return firstname + " " + lastname;
	}

	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public int getAnnualSalary() {
		return salary * 12;
	}

	public int raiseSalary(int percent) {
		salary = salary + (salary * percent / 100);
		return salary;
	}

	public String toString() {
		return "employee[id=" + id + ", name=" + getName() + ", salary=" + salary + "]";
	}
}
