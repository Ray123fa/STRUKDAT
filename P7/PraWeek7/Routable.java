// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public interface Routable {
  void findBestRoute(Location start, Location end);
}

class WalkingRoute implements Routable {
  @Override
  public void findBestRoute(Location start, Location end) {
    System.out.println("Implementation of walking routes");
  }
}

class CarRoute implements Routable {
  @Override
  public void findBestRoute(Location start, Location end) {
    System.out.println("Implementation of car routes");
  }
}

class MotorcycleRoute implements Routable {
  @Override
  public void findBestRoute(Location start, Location end) {
    System.out.println("Implementation of motorcycle routes");
  }
}