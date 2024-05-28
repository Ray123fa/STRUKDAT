<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Ajax Demonstration</title>

	<style>
		.displaybox {
			display: table-cell;
			vertical-align: middle;
			width: max-content;
			height: 40px;
			background-color: #FFFFFF;
			border: 2px solid #000000;
			padding: 10px;
			font: 1.5em normal verdana, helvetica, arial, sans-serif;
		}
	</style>
</head>

<body onload="autoUpdateTime()">
	<h1>Ajax Demonstartion</h1>
	<h2>Getting the server time without refreshing the page</h2>
	<!-- <form action="">
		<input type="button" value="Get Server Time" onclick="getServerTime()">
	</form><br> -->
	<div id="showtime" class="displaybox"></div>

	<script>
		var ajaxRequest;

		function ajaxResponse() {
			if (ajaxRequest.readyState != 4) {
				return;
			} else {
				if (ajaxRequest.status == 200) {
					document.getElementById("showtime").innerHTML = ajaxRequest.responseText;
				} else {
					alert("Request failed: " + ajaxRequest.statusText);
				}
			}
		}

		function getServerTime() {
			ajaxRequest = new XMLHttpRequest();
			var svcUrl = "telltime.php";
			ajaxRequest.onreadystatechange = ajaxResponse;
			ajaxRequest.open("GET", svcUrl);
			ajaxRequest.send(null);
		}

		function autoUpdateTime() {
			getServerTime();
			setInterval(getServerTime, 1000);
		}
	</script>
</body>

</html>