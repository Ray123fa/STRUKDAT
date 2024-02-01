// Muhammad Rayhan Faridh
// 222212766
// 2KS1

import java.lang.Override;

class author {
	private String name;
	private String email;
	private char gender;

	public author(String name, String email, char gender) {
		this.name = name;
		this.email = email;
		this.gender = gender;
	}

	public String getName() {
		return name;
	}

	public String getEmail() {
		return email;
	}

	public char getGender() {
		return gender;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	@Override
	public String toString() {
		return String.format("Author[name=%s, email=%s, gender=%c]", name, email, gender);
	}
}
