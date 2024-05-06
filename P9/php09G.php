<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

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
	$stmt = $pdo->prepare("SELECT * FROM meetings WHERE slot = :slot");
	$stmt->execute(array(':slot' => $_GET['slot']));
	$row = $stmt->fetch();
	$pdo = NULL;
} catch (PDOException $e) {
	exit("PDO Error: " . $e->getMessage() . "<br>");
}

if ($stmt->rowCount() == 0) {
	echo "Data tidak ditemukan<br>";
} else {
	$slot = $_GET['slot'];
?>
	<!DOCTYPE html>
	<html lang="en">

	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>PHP 09G</title>
	</head>

	<body>
		<form action="php09G_action.php" method="POST">
			<h2>Form Edit Data Meeting</h2>
			<label>Slot: <input type="text" name="slot" value="<?= $slot ?>" readonly></label><br>
			<label>Name: <input type="text" name="name" value="<?= $row['name'] ?>"></label><br>
			<label>Email: <input type="email" name="email" value="<?= $row['email'] ?>"></label><br>
			<button type="submit" style="margin-top: 10px;">Submit</button>
		</form>
	</body>

	</html>
<?php
}
?>