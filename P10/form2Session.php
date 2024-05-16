<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();
if (isset($_REQUEST['item'])) {
	$_SESSION['item'] = $_REQUEST['item'];
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Form 2 Session</title>
</head>

<body>
	<form action="processSession.php" method="post">
		<label for="address">Address: <input type="text" name="address"></label>
		<button type="submit">Send</button>
	</form>
</body>

</html>