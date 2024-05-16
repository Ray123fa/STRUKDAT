<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();
require_once "db.php";

if (!isset($_SESSION['username'])) {
	header("Location: php10A.php");
	exit();
}

try {
	$stmt = $pdo->prepare("INSERT INTO meetings (slot, name, email) VALUES (:slot, :name, :email)");
	$stmt->bindParam(':slot', $_REQUEST['slot'], PDO::PARAM_INT);
	$stmt->bindParam(':name', $_REQUEST['name'], PDO::PARAM_STR);
	$stmt->bindParam(':email', $_REQUEST['email'], PDO::PARAM_STR);
	$stmt->execute();

	if ($stmt->rowCount() == 1) {
		return header("Location: php10F.php");
	} else {
		echo "Gagal menambahkan data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
