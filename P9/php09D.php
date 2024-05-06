<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 09D</title>
</head>

<body>
	<h1>PHP and Databases</h1>

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
		echo "<h2>Data in meeting table (While loop)</h2>\n";
		$stmt = $pdo->query('SELECT * FROM meetings');
		echo "Rows retrieved: " . $stmt->rowcount() . "<br><br>\n";
		while ($row = $stmt->fetch()) {
			echo "Slot: ", $row["slot"], "<br>\n";
			echo "Name: ", $row["name"], "<br>\n";
			echo "Email: ", $row["email"], "<br><br>\n";
		}
		echo "<h2>Data in meeting table (Foreach loop)</h2>\n";
		$stmt = $pdo->query("select * from meetings");
		foreach ($stmt as $row) {
			echo "Slot: ", $row["slot"], "<br>\n";
			echo "Name: ", $row["name"], "<br>\n";
			echo "Email: ", $row["email"], "<br><br>\n";
		}
		$pdo = NULL;
	} catch (PDOException $e) {
		exit("PDO Error: " . $e->getMessage() . "<br>");
	}
	?>
</body>

</html>