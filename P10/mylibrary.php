<!-- Muhammad Rayhan Faridh -->
<!-- 222212766 -->
<!-- 2KS1 -->

<?php
session_start();

function destroy_session_and_data()
{
	session_unset();
	if (session_id() != "" || isset($_COOKIE[session_name()])) {
		setcookie(session_name(), session_id(), time() - 2592000, '/');
	}
	session_destroy();
}

function count_requests()
{
	if (!isset($_SESSION['requests'])) {
		if (!isset($_COOKIE['requests'])) {
			$_SESSION['requests'] = 1;
			setcookie('requests', $_SESSION['requests'] + 1, time() + 2592000, '/');
		} else {
			$_SESSION['requests'] = (int) $_COOKIE['requests'];
			setcookie('requests', $_SESSION['requests'] + 1, time() + 2592000, '/');
		}
	} else {
		$_SESSION['requests']++;
		setcookie('requests', $_SESSION['requests'] + 1, time() + 2592000, '/');
	}
	return $_SESSION['requests'];
}
