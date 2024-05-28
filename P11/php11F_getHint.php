<?php
require_once "../db.php";

try {
	$stmt = $pdo->query("SELECT name FROM meetings WHERE name LIKE '%" . $_GET['keyword'] . "%'");
	$rows = $stmt->fetchAll();

	$hint = "";
	if ($stmt) {
		foreach ($rows as $row) {
			if ($hint === "") {
				$hint = $row['name'];
			} else {
				$hint .= ", " . $row['name'];
			}
		}
	}
	echo $hint === "" ? "No suggestion" : $hint;

	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}
