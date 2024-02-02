// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.time.LocalDate;

public class NumberSix {
	public static void main(String[] args) {
		Customer6 c1 = new Customer6("Rayhan");
		Customer6 c2 = new Customer6("Faridh");
		Customer6 c3 = new Customer6("Rayfa");
		c1.setMember(true);
		c1.setMemberType("Premium");
		c3.setMember(true);
		c3.setMemberType("Gold");

		Visit v1 = new Visit(c1, LocalDate.of(2024, 1, 11));
		v1.setServiceExpense(9.8);
		v1.setProductExpense(8.5);
		System.out.println(v1.toString() + "\n");

		Visit v2 = new Visit(c1, LocalDate.now());
		v2.setServiceExpense(10);
		v2.setProductExpense(9);
		System.out.println(v2.toString() + "\n");

		Visit v3 = new Visit(c2, LocalDate.now());
		v3.setServiceExpense(100);
		v3.setProductExpense(50);
		System.out.println(v3.toString() + "\n");

		Visit v4 = new Visit(c3, LocalDate.now());
		v4.setServiceExpense(7.5);
		v4.setProductExpense(8);
		System.out.println(v4);
	}
}
