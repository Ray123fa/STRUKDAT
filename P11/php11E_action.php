<?php
require_once "../db.php";

if (!isset($_POST['slot']) || !isset($_POST['name']) || !isset($_POST['email'])) {
	header("Location: php11E.php");
	exit();
}

try {
	$stmt = $pdo->prepare("INSERT INTO meetings (slot, name, email) VALUES (:slot, :name, :email)");
	$stmt->bindParam(':slot', $_POST['slot'], PDO::PARAM_INT);
	$stmt->bindParam(':name', $_POST['name'], PDO::PARAM_STR);
	$stmt->bindParam(':email', $_POST['email'], PDO::PARAM_STR);
	$stmt->execute();

	if ($stmt->rowCount() == 1) {
		return header("Location: php11F.php");
	} else {
		echo "Gagal menambahkan data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
