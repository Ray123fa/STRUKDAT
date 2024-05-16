<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
require_once "../db.php";

try {
	$stmt = $pdo->prepare("INSERT INTO meetings (slot, name, email) VALUES (:slot, :name, :email)");
	$stmt->execute(array(':slot' => $_REQUEST['slot'], ':name' => $_REQUEST['name'], ':email' => $_REQUEST['email']));

	if ($stmt->rowCount() == 1) {
		return header("Location: php09F.php");
	} else {
		echo "Gagal menambahkan data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
