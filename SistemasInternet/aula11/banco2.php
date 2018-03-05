<?php
	$h="localhost";
	$u="root";
	$s="";
	$c=mysql_connect($h,$u,$s);
	if(!$c)
	{
		echo "Erro no connect: ";
		echo mysql_error();
		die(); //mata o script
	}
	if(!mysql_select_db("agenda"))
	{
		echo "Erro no select db: ";
		echo mysql_error();
		die(); 
	}
	$nome="Renato Mauro";
	$email="renato.mauro@gmail.com";
	$telefone="4444-4444";
	$sql="insert into 
		contato(nome,email,telefone) 
		values('$nome','$email','$telefone')";
	$res=mysql_query($sql);
	if($res)
	{
		echo "OK!";
	}
	else
	{
		echo "Erro na consulta: ";
		echo mysql_error();
		die(); 
	}
	
	mysql_close($c);
?>