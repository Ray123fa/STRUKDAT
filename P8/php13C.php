<?php
function reduceOp(...$args)
{
	/**
	 * Mengecek apakah argumen terakhir dari array $args merupakan array asosiatif.
	 *
	 * @param array $args Array yang akan dicek argumen terakhirnya.
	 * @throws TypeError Jika argumen terakhir bukan merupakan array asosiatif.
	 */
	if (!is_array(end($args))) {
		throw new TypeError("Argumen terakhir harus berupa array asosiatif");
	}

	/**
	 * Mengecek apakah nilai 'op' pada array asosiatif valid.
	 *
	 * @param array $assoc_array Array asosiatif yang akan dicek nilainya.
	 * @throws ValueError Jika nilai 'op' pada array asosiatif tidak valid.
	 */
	$assoc_array = array_pop($args);
	if (!isset($assoc_array['op']) || !in_array($assoc_array['op'], ['+', '-', '*'])) {
		throw new ValueError("Nilai 'op' pada array asosiatif tidak valid");
	}

	$operator = $assoc_array['op'];
	if (empty($args)) {
		echo "NULL";
		return NULL;
	}

	$result = array_shift($args);
	foreach ($args as $arg) {
		switch ($operator) {
			case '+':
				$result += $arg;
				break;
			case '-':
				$result -= $arg;
				break;
			case '*':
				$result *= $arg;
				break;
		}
	}

	return $result;
}
?>

<!DOCTYPE html>
<html lang='en-GB'>

<head>
	<title>PHP 13C</title>
	<meta name="description" content="php13C.php">
</head>

<body>
	<h1>Variable-length Argument Lists</h1>
	<?php
	// Di comment karena akan menghasilkan error
	// try {
	// 	echo "1: ", reduceOp(2, 3), "<br>\n"; # throws an exception
	// } catch (Exception $e) {
	// 	echo "1: Exception ", $e->getMessage(), "<br>\n"; # TypeError
	// }

	// Di comment karena akan menghasilkan error
	// try {
	// 	echo "2: ", reduceOp(2, 3, ['op' => '/']), "<br>\n"; # throws an exception
	// } catch (Exception $e) {
	// 	echo "2: Exception ", $e->getMessage(), "<br>\n"; # ValueError
	// }

	echo "3: ", reduceOp(array('op' => '+')), "<br>\n"; # NULL
	echo "4: ", reduceOp(2, array('op' => '*')), "<br>\n"; # 2
	echo "5: ", reduceOp(2, 3, 5, array('op' => '+')), "<br>\n"; # 10
	echo "6: ", reduceOp(2, 3, 5, 7, array('op' => '*')), "<br>\n"; # 210
	echo "7: ", reduceOp(2, 3, 5, 7, 11, array('op' => '-')), "<br>\n"; # -24
	?>
</body>

</html>