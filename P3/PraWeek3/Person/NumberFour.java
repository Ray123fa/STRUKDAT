// Muhammad Rayhan Faridh
// 222212766
// 2KS1

public class NumberFour {
	public static void main(String[] args) {
		Person p1 = new Student("Rayhan", "Bonasel", "LPDP", 2020, 4000000);
		Student s1 = (Student) p1;
		System.out.println("Nama: " + p1.getName());
		System.out.println("Alamat: " + p1.getAddress());
		System.out.println("Program: " + s1.getProgram());
		System.out.println("Tahun: " + s1.getYear());
		System.out.println("Biaya: " + s1.getFee());
		System.out.println(s1.toString() + "\n");

		Person p2 = new Staff("Rayfa", "Bonsay", "Polstat STIS", 5000000);
		Staff s2 = (Staff) p2;
		System.out.println("Nama: " + p2.getName());
		System.out.println("Alamat: " + p2.getAddress());
		System.out.println("Sekolah: " + s2.getSchool());
		System.out.println("Gaji: " + s2.getPay());
	}
}
