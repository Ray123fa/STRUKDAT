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
	$stmt = $pdo->prepare("DELETE FROM meetings WHERE slot = :slot");
	$stmt->bindParam(':slot', $_GET['slot'], PDO::PARAM_INT);
	$stmt->execute();

	if ($stmt->rowCount() == 1) {
		return header("Location: php10F.php");
	} else {
		echo "Gagal menghapus data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
