// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class Coordinates {
	private double latitute;
	private double longitude;

	public Coordinates(double latitute, double longitude) {
		this.latitute = latitute;
		this.longitude = longitude;
	}

	public double getLatitute() {
		return latitute;
	}

	public void setLatitute(double latitute) {
		this.latitute = latitute;
	}

	public double getLongitude() {
		return longitude;
	}

	public void setLongitude(double longitude) {
		this.longitude = longitude;
	}

	@Override
	public String toString() {
		return "Coordinates[" +
				"latitute=" + latitute +
				", longitude=" + longitude + ']';
	}
}
