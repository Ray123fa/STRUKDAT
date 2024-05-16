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
		session_destroy();
		header("Location: form1Session.php");
	}
}
$_SESSION['timeout'] = time();
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Process Session</title>
</head>

<body>
	<?php
	echo $_SESSION['item'] . "<br>";
	echo $_SESSION['address'];
	?>
</body>

</html>