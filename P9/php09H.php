<?php
$db_hostname = "localhost";
$db_username = "root";
$db_password = "root";
$db_database = "pbw";

$dsn = "mysql:host=$db_hostname;dbname=$db_database";
$opt = array(
	PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
	PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
	PDO::ATTR_EMULATE_PREPARES => false
);

try {
	$pdo = new PDO($dsn, $db_username, $db_password, $opt);
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
