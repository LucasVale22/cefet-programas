<h1>CPF</h1>

<?php
function tiralixo($cpf)
	{
		$resp="";
		for($i=0;$i<strlen($cpf);$i++)
		{
			
		}
			
	}
function calcdvcpf($cpf)
	{
	$soma=0;
	$soma2=0;
	for($i=0;$i<strlen($cpf);$i++) //strlen() devolve a quantidade de caracteres na cadeia...
		{
			$c=$cpf[$i];
			$soma+=$c*($i+1);
			$soma2+=$c*$i;
		}
	$dv1=$soma%11;
	if($dv1==10)
		{
			$dv1=0;
		}
	$soma2+=$dv1*9;
	$dv2=$soma2%11;
	if($dv2==0)
		{
			$dv2=0;
		}
	return "$dv1$dv2";
	}
	echo calcdvcpf("025844797");
	
?>
	

