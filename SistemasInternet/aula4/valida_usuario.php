<?php
	$email=$_REQUEST["email"];
	$senha=$_REQUEST["senha"];
	if(($email=="x@y") && ($senha=="123")){
		session_start();
		$_SESSION["email"]=$email;
		header("location: pag1.php");
		}
	else{
		echo "usuario invalido";
		include "login.php";
	}
?>