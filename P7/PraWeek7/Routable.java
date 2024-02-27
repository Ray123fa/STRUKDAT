// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public interface Routable {
	void findBestRoute(Location start, Location end);
}

class WalkingRoute implements Routable {
	@Override
	public void findBestRoute(Location start, Location end) {
		System.out.println("The implementation of walking route goes here...");
	}
}

class CarRoute implements Routable {
	@Override
	public void findBestRoute(Location start, Location end) {
		System.out.println("The implementation of car route goes here...");
	}
}

class MotorcycleRoute implements Routable {
	@Override
	public void findBestRoute(Location start, Location end) {
		System.out.println("The implementation of motor route goes here...");
	}
}