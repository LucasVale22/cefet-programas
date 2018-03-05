<?php
	session_start();
	$usuario=$_REQUEST['usuario'];
	$senha=$_REQUEST['senha'];
	
	$senhas=array
	(
		array("Fulano","1234","Seja Bem Vindo!"),
		array("Beltrano","4567","Bom Dia!"),
		array("Siclano","9999","Bom te ver por aqui"),
	);
	
	
		foreach($senhas as $u)
		{		
			if(($usuario==$u[0]) && ($senha==$u[1]))
			{
				$_SESSION['usuario']=$usuario;
				$_SESSION['senha']=$senha;
				$_SESSION['mensagem']=$u[2];
				header("location:aviso.php");
				exit();
			}
		}
	echo "<h1 style='color:red;'>ERRO! Usuário inexistente!</h1></br>";
	echo "<a style='font-size:16px;font-family:verdana'href='Login.php'>Voltar à área de acesso...</a>";
?>