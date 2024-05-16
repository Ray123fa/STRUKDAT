<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();
require_once "db.php";

if (isset($_POST['username']) && isset($_POST['password'])) {
	try {
		$username = $_POST['username'];
		$password = $_POST['password'];
		$stmt = $pdo->prepare("SELECT * FROM user WHERE username = :username");
		$stmt->bindParam(':username', $username);
		$stmt->execute();

		if ($stmt->rowCount() == 1) {
			$row = $stmt->fetch();
			if (password_verify($password, $row['password'])) {
				$_SESSION['username'] = $username;
				header("Location: php10F.php");
			} else {
				echo '
				<script>
					alert("Password salah")
					window.location.href = "php10A.php"
				</script>
				';
			}
		} else {
			echo '
			<script>
				alert("Username tidak ditemukan")
				window.location.href = "php10A.php"
			</script>
			';
		}
		$pdo = NULL;
	} catch (Exception $e) {
		exit("Error: " . $e->getMessage());
	}
} else {
	header("Location: php10A.php");
	exit();
}
