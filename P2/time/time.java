// Muhammad Rayhan Faridh
// 222212766
// 2KS1

class time {
	private int hour, minute, second;

	public time(int hour, int minute, int second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}

	public time() {
		this(0, 0, 0);
	}

	public int getHour() {
		return this.hour;
	}

	public int getMinute() {
		return this.minute;
	}

	public int getSecond() {
		return this.second;
	}

	public void setHour(int hour) {
		this.hour = hour;
	}

	public void setMinute(int minute) {
		this.minute = minute;
	}

	public void setSecond(int second) {
		this.second = second;
	}

	public void setTime(int hour, int minute, int second) {
		this.hour = hour;
		this.minute = minute;
		this.second = second;
	}

	public String toString() {
		return String.format("%02d:%02d:%02d", this.hour, this.minute, this.second);
	}

	public time nextSecond() {
		++this.second;
		if (this.second >= 60) {
			this.second = 0;
			++this.minute;
			if (this.minute >= 60) {
				this.minute = 0;
				++this.hour;
				if (this.hour >= 24) {
					this.hour = 0;
				}
			}
		}
		return this;
	}

	public time previousSecond() {
		--this.second;
		if (this.second < 0) {
			this.second = 59;
			--this.minute;
			if (this.minute < 0) {
				this.minute = 59;
				--this.hour;
				if (this.hour < 0) {
					this.hour = 23;
				}
			}
		}
		return this;
	}
}
