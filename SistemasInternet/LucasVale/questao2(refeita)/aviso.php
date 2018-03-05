<?php
	session_start();
	$FRASE=$_SESSION['usuario'].", ".$_SESSION['mensagem'];
	echo "<h1 style='color:blue;font-family:arial;'>$FRASE</h1>";
	echo "<a style='font-size:16px;font-family:arial' href='Login.php'>Voltar à área de acesso...</a>";
	
?>