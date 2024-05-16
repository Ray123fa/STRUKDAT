<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
require_once "db.php";

try {
	$stmt = $pdo->prepare("DELETE FROM meetings WHERE slot = :slot");
	$stmt->execute(array(':slot' => $_GET['slot']));

	if ($stmt->rowCount() == 1) {
		return header("Location: php09F.php");
	} else {
		echo "Gagal menghapus data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
