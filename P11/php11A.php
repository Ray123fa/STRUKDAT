<?php
$data = file_get_contents("https://reqres.in/api/users?page=1");
$parse_data = json_decode($data, true);
?>

<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>PHP 11A</title>

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
	<table>
		<tr>
			<th>ID</th>
			<th>Email</th>
			<th>First Name</th>
			<th>Last Name</th>
			<th>Avatar</th>
		</tr>
		<?php foreach ($parse_data['data'] as $row) : ?>
			<tr>
				<td><?= $row['id']; ?></td>
				<td><?= $row['email']; ?></td>
				<td><?= $row['first_name']; ?></td>
				<td><?= $row['last_name']; ?></td>
				<td><img src="<?= $row['avatar']; ?>" alt="Avatar"></td>
			</tr>
		<?php endforeach; ?>
	</table>
</body>

</html>