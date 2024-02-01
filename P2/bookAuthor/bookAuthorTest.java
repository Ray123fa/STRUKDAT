// Muhammad Rayhan Faridh
// 222212766
// 2KS1

class bookAuthorTest {
	static void authorTest(author[] authors) {
		for (author author : authors) {
			System.out.println(author.toString());
			System.out.printf("Nama: %s\n", author.getName());
			System.out.printf("Email: %s\n", author.getEmail());
			System.out.printf("Jenis Kelamin: %c\n\n", author.getGender());
		}
	}

	static void bookTest(book book) {
		System.out.println(book.toString());
		System.out.printf("Judul Buku: %s\n", book.getName());
		System.out.printf("Penulis: %s\n", book.getAuthorNames());
		System.out.printf("Harga: %.2f\n", book.getPrice());
		System.out.printf("Stok: %d\n\n", book.getQty());
	}

	public static void main(String[] args) {
		author[] authors = new author[3];
		authors[0] = new author("Rayhan", "ray16fa@gmail.com", 'L');
		authors[1] = new author("Faridh", "12766@stis.ac.id", 'L');
		authors[1].setEmail("222212766@stis.ac.id");
		authors[2] = new author("Rayfa", "rayfa@gmail.com", 'L');

		book book1 = new book("Learning Java", authors, 20, 99);
		book1.setPrice(30);
		book book2 = new book("Java Programming", authors, 24.99, 1);
		book2.setQty(15);

		authorTest(authors);
		bookTest(book1);
		bookTest(book2);
	}
}
