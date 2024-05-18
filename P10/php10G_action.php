<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();
require_once "../db.php";

if (!isset($_SESSION['username'])) {
	header("Location: php10D.php");
	exit();
}

if (!isset($_POST['slot']) || !isset($_POST['name']) || !isset($_POST['email'])) {
	header("Location: php10F.php");
	exit();
}

try {
	$stmt = $pdo->prepare("UPDATE meetings SET name = :name, email = :email WHERE slot = :slot");
	$stmt->bindParam(':slot', $_POST['slot'], PDO::PARAM_INT);
	$stmt->bindParam(':name', $_POST['name'], PDO::PARAM_STR);
	$stmt->bindParam(':email', $_POST['email'], PDO::PARAM_STR);
	$stmt->execute();

	if ($stmt->rowCount() == 1) {
		return header("Location: php10F.php");
	} else {
		echo "Gagal update data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
