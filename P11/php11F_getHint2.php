<?php
require_once "../db.php";

try {
	$stmt = $pdo->query("SELECT name FROM meetings WHERE name LIKE '%" . $_GET['keyword'] . "%'");
	$rows = $stmt->fetchAll();

	if ($stmt) {
		echo json_encode($rows);
	}

	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
