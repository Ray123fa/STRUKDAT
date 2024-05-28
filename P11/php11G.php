<?php
require_once "../db.php";

if (!isset($_GET['slot'])) {
	header("Location: php11F.php");
	exit();
}

try {
	$stmt = $pdo->prepare("SELECT * FROM meetings WHERE slot = :slot");
	$stmt->bindParam(':slot', $_GET['slot'], PDO::PARAM_INT);
	$stmt->execute();
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
		<title>PHP 11G</title>
	</head>

	<body>
		<form action="php11G_action.php" method="POST">
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