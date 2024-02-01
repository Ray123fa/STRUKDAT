// Muhammad Rayhan Faridh
// 222212766
// 2KS1

// To test time.java

public class timeTest {
	static void _nextSecond(time t) {
		System.out.println("Sebelum-> " + t.toString());
		System.out.println("Sesudah-> " + t.nextSecond().toString());
	}

	static void showNextSecond(time t1, time t2, time t3) {
		System.out.println("Percobaan Next Second");
		_nextSecond(t1);
		System.out.println();
		_nextSecond(t2);
		System.out.println();
		_nextSecond(t3);
	}

	static void _previousSecond(time t) {
		System.out.println("Sebelum-> " + t.toString());
		System.out.println("Sesudah-> " + t.previousSecond().toString());
	}

	static void showPreviousSecond(time t1, time t2, time t3) {
		System.out.println("Percobaan Previous Second");
		_previousSecond(t1);
		System.out.println();
		_previousSecond(t2);
		System.out.println();
		_previousSecond(t3);
	}

	static void _setHour(time t, int hour) {
		System.out.println("Sebelum set hour-> " + t.getHour());
		t.setHour(hour);
		System.out.println("Sesudah set hour-> " + t.getHour());
	}

	static void _setMinute(time t, int minute) {
		System.out.println("Sebelum set minute-> " + t.getMinute());
		t.setMinute(minute);
		System.out.println("Sesudah set minute-> " + t.getMinute());
	}

	static void _setSecond(time t, int second) {
		System.out.println("Sebelum set second-> " + t.getSecond());
		t.setSecond(second);
		System.out.println("Sesudah set second-> " + t.getSecond());
	}

	public static void main(String[] args) {
		time t1 = new time(10, 0, 59);
		time t2 = new time(10, 59, 59);
		time t3 = new time(23, 59, 59);
		showNextSecond(t1, t2, t3);

		System.out.println();
		time t4 = new time(10, 1, 0);
		time t5 = new time(10, 0, 0);
		time t6 = new time(0, 0, 0);
		showPreviousSecond(t4, t5, t6);

		System.out.println();
		System.out.println("Percobaan set/get hour, minute, dan second");
		_setHour(t1, 8);
		_setMinute(t1, 12);
		_setSecond(t1, 30);

		System.out.println();
		System.out.println("Percobaan set time");
		System.out.println("Sebelum set time-> " + t1.toString());
		t1.setTime(12, 40, 35);
		System.out.println("Sesudah set time-> " + t1.toString());
	}
}