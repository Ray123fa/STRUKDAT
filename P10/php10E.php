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
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 10E</title>
</head>

<body>
	<form action="php10E_action.php" method="POST">
		<h2>Form Menambahkan Data Meeting</h2>
		<label style="margin-top: 5px;">Slot: <input type="text" name="slot"></label><br>
		<label>Name: <input type="text" name="name"></label><br>
		<label>Email: <input type="email" name="email"></label><br>
		<button type="submit" style="margin-top: 10px;">Submit</button>
	</form>
</body>

</html>