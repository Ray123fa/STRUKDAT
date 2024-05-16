<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 09F</title>

	<style>
		table,
		th,
		td {
			border: 1px solid black;
			border-collapse: collapse;
			padding: 5px;
		}
	</style>
</head>

<body>
	<?php
	require_once "db.php";

	try {
		echo "<h2>Data Meeting</h2>\n";
		$stmt = $pdo->query("SELECT * FROM meetings ORDER BY slot");
		if ($stmt->rowCount() == 0) {
			echo "Data tidak ditemukan<br>";
		} else {
	?>
			<table>
				<tr>
					<th>Slot</th>
					<th>Name</th>
					<th>Email</th>
					<th colspan="2">Aksi</th>
				</tr>
				<?php foreach ($stmt as $row) : ?>
					<tr>
						<td><?= $row['slot']; ?></td>
						<td><?= $row['name']; ?></td>
						<td><?= $row['email']; ?></td>
						<td>
							<a href="php09G.php?slot=<?= $row['slot']; ?>">
								<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="20" height="20" class="main-grid-item-icon" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2">
									<path d="M11 4H4a2 2 0 0 0-2 2v14a2 2 0 0 0 2 2h14a2 2 0 0 0 2-2v-7" />
									<path d="M20.5 2.5a2.121 2.121 0 0 1 3 3L12 15l-4 1 1-4 9.5-9.5z" />
								</svg>
							</a>
						</td>
						<td>
							<a href="php09H.php?slot=<?= $row['slot']; ?>">
								<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="20" height="20" class="main-grid-item-icon" fill="none" stroke="currentColor" stroke-linecap="round" stroke-linejoin="round" stroke-width="2">
									<polyline points="3 6 5 6 21 6" />
									<path d="M19 6v14a2 2 0 0 1-2 2H7a2 2 0 0 1-2-2V6m3 0V4a2 2 0 0 1 2-2h4a2 2 0 0 1 2 2v2" />
									<line x1="10" x2="10" y1="11" y2="17" />
									<line x1="14" x2="14" y1="11" y2="17" />
								</svg>
							</a>
						</td>
					</tr>
				<?php endforeach; ?>
			</table>
			<button type='button' style='margin-top: 10px'>
				<a href='php09E.php' style='text-decoration:none; color: black'>Tambah Data</a>
			</button>
	<?php
		}
		$pdo = NULL;
	} catch (PDOException $e) {
		exit("PDO Error: " . $e->getMessage() . "<br>");
	}
	?>
</body>

</html>