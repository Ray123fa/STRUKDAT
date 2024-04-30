<!DOCTYPE html>
<html>

<head>
	<title>PHP 12B</title>
</head>

<body>
	<h1>Array Operators and Regular Expressions</h1>
	<?php
	echo "<h2>Exercise 2a</h2>\n";
	$planets = array("earth");
	array_unshift($planets, "mercury", "venus");
	array_push($planets, "mars", "jupiter", "saturn");
	echo "(1) \$planets = [", join(", ", $planets), "]<br>\n";
	$last = array_pop($planets);
	echo "(2) \$planets = [", join(", ", $planets), "]<br>\n";
	$first = array_shift($planets);
	echo "(3) \$planets = [", join(", ", $planets), "]<br>\n";
	echo "(4) \$first = $first, \$last = $last<br>\n";

	echo "<h2>Exercise 2c</h2>\n";
	$spheres = $planets;
	echo "(5) \$spheres = [", join(", ", $spheres), "]<br>\n";
	$planets[1] = "midgard";
	echo "(6) \$planets = [", join(", ", $planets), "]<br>\n";
	echo "(6) \$spheres = [", join(", ", $spheres), "]<br>\n";
	$spheres = &$planets;
	echo "(7) \$spheres = [", join(", ", $spheres), "]<br>\n";
	$planets[0] = "friga";
	echo "(8) \$planets = [", join(", ", $planets), "]<br>\n";
	echo "(8) \$spheres = [", join(", ", $spheres), "]<br><br>\n";

	for ($i = 0; $i <= count($planets) + 2; $i++) {
		echo "Removed: $planets[$i]\n";
		unset($planets[$i]);
		echo "Remaining: [", join(", ", $planets), "]<br>\n";
	}

	echo "<h2>Exercise 3</h2>\n";
	$names = [
		"Dave Shield", "Mr Andy Roxburgh",
		"Dr George Christodoulou", "Dr Ullrich Hustadt", "Dr David Jackson"
	];
	foreach ($names as $name) echo "(1) Name: $name<br>\n";
	foreach ($names as &$name) {
		$parts = explode(" ", $name);
		if (count($parts) == 2)
			$name = strtoupper($parts[1]) . ", " . $parts[0];
		else
			$name = strtoupper($parts[2]) . ", " . $parts[1];
	}
	foreach ($names as &$name) echo "(2) Name: $name<br>\n";
	?>
</body>

</html>