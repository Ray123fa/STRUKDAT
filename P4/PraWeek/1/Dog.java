// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Dog extends Animal {
	public Dog(String name) {
		super(name);
	}

	@Override
	public void greets() {
		System.out.println("Woof");
	}

	public void greets(Dog another) {
		System.out.println("Wooof");
	}
}