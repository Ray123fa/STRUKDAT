// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Location {
	private String name;
	private Coordinates coordinates;

	public Location(String name, Coordinates coordinates) {
		this.name = name;
		this.coordinates = coordinates;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Coordinates getCoordinates() {
		return coordinates;
	}

	public void setCoordinates(Coordinates coordinates) {
		this.coordinates = coordinates;
	}

	@Override
	public String toString() {
		return "Location{" +
				"name='" + name + '\'' +
				", coordinates=" + coordinates +
				'}';
	}
}
