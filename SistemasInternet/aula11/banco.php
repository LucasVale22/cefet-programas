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
	$sql="select * from contato";
	
	$res=mysql_query($sql);
	if($res)
	{
		$linha=mysql_fetch_assoc($res);
		if($linha)
		{
			while($linha)
			{
				echo 
				"	
					<table cellpadding='10'>
						<tr>
							<td width='300'>
								{$linha["nome"]}
							</td>
							<td width='300'>
								{$linha["email"]}
							</td>
							<td width='300'>
								{$linha["telefone"]}
							<td/>
						</tr>
					</table>
				";
				$linha=mysql_fetch_assoc($res);
			}
		}
		else
		{
			echo "Vazio";
		}
		echo "OK!<br/>";
		mysql_free_result($res); //ajuda o banco de dados, desalocando a memória
	}
	else
	{
		echo "Erro na consulta: ";
		echo mysql_error();
		die(); 
	}
	mysql_close($c);
	echo "<a href='formulario'><= HOME<a/>";
?>