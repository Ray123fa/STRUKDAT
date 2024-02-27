// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class AllTest {
  public static void main(String[] args) {
    Location kostKu = new Location(
        "Kostku",
        new Coordinates(-6.232d, 106.868802));
    Location kampus = new Location(
        "STIS",
        new Coordinates(-6.231d, 106.867525));

    Route bestRoute = new Walking(kostKu, kampus);
    bestRoute.printRoute();

    bestRoute = new Riding(kostKu, kampus);
    bestRoute.printRoute();

    bestRoute = new Driving(kostKu, kampus);
    bestRoute.printRoute();
  }
}