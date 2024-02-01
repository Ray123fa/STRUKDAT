public class addIntegerArgs {
	public static void main(String[] args) {
		int sum = 0;
		for (int i = 0; i < args.length; i++) {
			System.out.printf("Argumen ke-%d: %s%n", i + 1, args[i]);
			sum = sum + Integer.parseInt(args[i]);
		}
		System.out.println("Jumlah: " + sum);
	}
}
