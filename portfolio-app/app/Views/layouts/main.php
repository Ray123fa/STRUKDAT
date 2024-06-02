<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>CI4 Portfolio App</title>

	<!-- Bootstrap 5 -->
	<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-YvpcrYf0tY3lHB60NNkmXc5s9fDVZLESaAA55NDzOxhy9GkcIdslK1eN7N6jIeHz" crossorigin="anonymous"></script>

	<style>
		body {
			margin-top: 30px;
		}
	</style>
</head>

<body>
	<div class="container">
		<?php echo $this->include('partials/navbar'); ?>
		<!-- Section content-->
		<?php echo $this->renderSection('content') ?>
		<!-- end Section Content -->
		<div class="row mt-4">
			<?php echo $this->include('partials/footer'); ?>
		</div>
	</div>

	<?php echo $this->renderSection('scripts') ?>
</body>

</html>