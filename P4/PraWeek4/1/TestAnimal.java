// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class TestAnimal {
	public static void main(String[] args) {
		// Subclass
		Cat cat1 = new Cat("Kitty");
		cat1.greets();
		Dog dog1 = new Dog("Doggy");
		dog1.greets();
		BigDog bigDog1 = new BigDog("Big Doggy");
		bigDog1.greets();

		// Polymorphism
		System.out.println();
		Animal animal1 = new Cat("Kitty");
		animal1.greets();
		Animal animal2 = new Dog("Doggy");
		animal2.greets();
		Animal animal3 = new BigDog("Big Doggy");
		animal3.greets();

		// Downcast
		System.out.println();
		Dog dog2 = (Dog) animal2;
		BigDog bigDog2 = (BigDog) animal3;
		Dog dog3 = (Dog) animal3;
		dog2.greets(dog3);
		dog3.greets(dog2);
		dog2.greets(bigDog2);
		bigDog2.greets(dog2);
		bigDog2.greets(bigDog1);
	}
}