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
	return $pdo;
} catch (Exception $e) {
	echo "Error: " . $e->getMessage();
}
