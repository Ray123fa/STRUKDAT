<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();
if (isset($_REQUEST['address'])) {
	$_SESSION['address'] = $_REQUEST['address'];
}

$inactive = 5; // 5 seconds
if (isset($_SESSION['timeout'])) {
	$session_life = time() - $_SESSION['timeout'];
	if ($session_life > $inactive) {
		session_unset();
		session_destroy();
		header("Location: php10A.php");
	}
}
$_SESSION['timeout'] = time();
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 10C</title>
</head>

<body>
	<?php
	echo $_SESSION['item'] . "<br>";
	echo $_SESSION['address'];

	// session_unset();
	// session_destroy();
	?>
</body>

</html>