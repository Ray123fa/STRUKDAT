<?php
if (!isset($_SESSION['username'])) {
	header("Location: php10A.php");
	exit();
} else {
?>
	<header>
		<nav>
			<ul>
				<li><a href="#" class="active">Data Meeting</a></li>
				<li><a href="php10F_logout.php">Logout</a></li>
			</ul>
		</nav>
	</header>
<?php
}
?>