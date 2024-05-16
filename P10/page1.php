<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
require_once 'mylibrary.php';
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Page 1</title>
</head>

<body>
	Hello visitors! <br>
	This is your page request no <?php echo count_requests(); ?> from this site. <br>
	<a href="page1.php">Continue</a> | <a href="finish.php">Finish</a>

	<?php
	var_dump($_SESSION);
	var_dump($_COOKIE);
	?>
</body>

</html>