// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public interface Observable {
	void addObserver(Observer O);

	void removeObserver(Observer O);

	void notifyObserver();
}
