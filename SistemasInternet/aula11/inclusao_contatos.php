<?php
	$nome=$_REQUEST["nome"];
	$email=$_REQUEST["email"];
	$telefone=$_REQUEST["telefone"];
	$h="localhost";
	$u="root";
	$s="";
	$c=mysql_connect($h,$u,$s);
	if(!$c)
	{
		echo "Erro no connect: ";
		echo mysql_error();
		die(); 
	}
	if(!mysql_select_db("agenda"))
	{
		echo "Erro no select db: ";
		echo mysql_error();
		die(); 
	}
	$sql="insert into 
		contato(nome,email,telefone) 
		values('$nome','$email','$telefone')";
	$res=mysql_query($sql);
	if($res)
	{
		include "banco.php";
	}
	else
	{
		echo "Erro na consulta: ";
		echo mysql_error();
		die(); 
	}
	
	
?>