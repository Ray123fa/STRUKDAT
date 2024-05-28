<?php
require_once "../db.php";

if (!isset($_GET['slot'])) {
	header("Location: php11F.php");
	exit();
}

try {
	$stmt = $pdo->prepare("DELETE FROM meetings WHERE slot = :slot");
	$stmt->bindParam(':slot', $_GET['slot'], PDO::PARAM_INT);
	$stmt->execute();

	if ($stmt->rowCount() == 1) {
		return header("Location: php11F.php");
	} else {
		echo "Gagal menghapus data<br>";
	}
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
