<?php
	session_start();
	$email=$_SESSION["email"];
	if($email=""){
		echo "ESPERTO!";
		include "login.php";
		die();
		}
	echo "oi $email";
?>