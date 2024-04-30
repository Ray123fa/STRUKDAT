<!DOCTYPE html>
<html>

<head>
	<title>PHP 12C</title>

	<style>
		table {
			border-collapse: collapse;
			width: fit-content;
		}

		table,
		th,
		td {
			border: 1px solid black;
		}

		th,
		td {
			padding: 5px;
			text-align: center;
		}

		td.kata {
			text-align: left;
		}

		td.jumlah {
			text-align: right;
		}
	</style>
</head>

<body>
	<h1>Associative Arrays</h1>
	<?php
	$dict1 = array('a' => 1, 'b' => 2);
	$dict2 = $dict1;
	$dict1['b'] = 4;
	echo "\$dict1['b'] = ", $dict1['b'], "<br>\n";
	echo "\$dict2['b'] = ", $dict2['b'], "<br>\n";
	?>

	<span>Dict 1</span>
	<pre>
		<?= var_dump($dict1) ?>
	</pre>

	<span>Dict 2</span>
	<pre>
		<?= var_dump($dict2) ?>
	</pre>

	<?php
	$text = 'lorem ipsum elit congue auctor inceptos taciti suscipit tortor auctor integer congue hac nullam hac auctor tellus nullam inceptos nullam integer tellus nullam auctor elit lorem ipsum elit';
	$words = explode(' ', $text);
	$word_count = array();
	foreach ($words as $word) {
		if (array_key_exists($word, $word_count)) {
			$word_count[$word]++;
		} else {
			$word_count[$word] = 1;
		}
	}
	?>

	<span>Dict 3</span>
	<pre>
		<?= var_dump($word_count) ?>
	</pre>

	<table>
		<tr>
			<th>Kata</th>
			<th>Jumlah kemunculan</th>
		</tr>
		<?php
		arsort($word_count);
		foreach ($word_count as $word => $count) {
			echo "<tr><td class='kata'>$word</td><td class='jumlah'>$count</td></tr>\n";
		}
		?>
	</table>
</body>

</html>