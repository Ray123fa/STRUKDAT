<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 09B</title>
</head>

<body>
	<?php
	echo 'Item: ', $_REQUEST['item'], "<br>";
	echo '
		<form action="php09C.php" method="post">
		<input type="hidden" name="item" value="', $_REQUEST['item'], '">
		<label>Address: <input type="text" name="address"></label>
		</form>
	';
	?>
</body>

</html>