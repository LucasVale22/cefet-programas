<?php
	$resp=0;
	//T�TULO
	$titproj=$_REQUEST["titproj"];
	$tit_no_espace=trim($titproj," ");
	if(strlen($tit_no_espace)>40 || strlen($tit_no_espace)<20 && strlen($tit_no_espace)>0 ){
		echo "</br>O T�tulo do Projeto deve possuir entre 20 e 40 carateres!</br>";
		$resp++;
	}
	else{
		if(strlen($tit_no_espace)==0){
			echo "</br>O campo [T�tulo do Projeto] � obrigat�rio!</br>";
			$resp++;
		}
	}
	
	//DESCRI��O
	$descricao=$_REQUEST["descricao"];
	if(strlen($descricao)>2000){
		echo "</br>O campo [Descri��o] deve possuir no m�ximo, 2000 caracteres!</br>";
		$resp++;
	}

	//DATA DE IN�CIO
	$dinicio=$_REQUEST["dinicio"];
	$barra1=substr($dinicio,2,1);
	$barra2=substr($dinicio,5,1);
	if(strlen($dinicio)==0)
	{
			echo "</br>O campo [Data de In�cio] � obrigat�rio!</br>";
			$resp++;
	}
	else{
		if(($barra1!="/")||($barra2!="/"))
		{
			echo "<br>A data de in�cio deve estar no formato DD/MM/AAAA!</br>";
			$resp++;
		}
		else{
			$di=substr($dinicio,0,2);
			$mi=substr($dinicio,3,2);
			$ai=substr($dinicio,6,4);
			$dinicio=$ai.$mi.$di;
		}
	}
	//DATA DE T�RMINO
	$dtermino=$_REQUEST["dtermino"];
	if(strlen($dtermino)!=0)
	{
		$barra1=substr($dtermino,2,1);
		$barra2=substr($dtermino,5,1);
		if(($barra1!="/")||($barra2!="/"))
		{
			echo "<br>A data de t�rmino deve estar no formato DD/MM/AAAA!</br>";
			$resp++;
		}
		else
		{
			$dt=substr($dtermino,0,2);
			$mt=substr($dtermino,3,2);
			$at=substr($dtermino,6,4);
			$dtermino=$at.$mt.$dt;
			if($dtermino<=$dinicio)
			{
				echo "</br>A data de t�rmino deve ser posterior � de in�cio!</br>";
				$resp++;
			}
		}
	}
	
	//EMAIL DO RESPONS�VEL
	$email=$_REQUEST["email"];
	if(strlen($email)==0)
	{
		echo "</br>O campo[Email do Respons�vel] � obrigat�rio!</br>";
		$resp++;
	}
	else
	{
		$cont=0;
		for($i=0;$i<strlen($email); $i++)
		{
			$arroba=substr($email,$i,1);
			if($i!=0 && $arroba=='@' && $cont!=-1)
			{
				$cont++;
			}
			else
			{
				if($i==0 && $arroba=='@')
				{
					$cont=-1;
				}
			}
		}
		if($cont==-1)
		{
			echo "</br>O campo [Email do Respons�vel] est� incorreto! N�o pode haver o s�mbolo [@] como 1� caracter.</br> ";
			$resp++;
		}
		else
		{
			if($cont==0)
			{
				echo "</br>O campo [Email do Respons�vel] deve possuir o s�mbolo [@]!</br>";
				$resp++;
			}
			else
			{
				if($cont!=1)
				{
					echo "</br>O campo [Email do Respons�vel] est� incorreto! Existe(m) mais de um s�mbolo [@].</br>";
					$resp++;
				}
			}
		}
	}
	//Se todos os campos estiverem corretos...
	if($resp==0)
	{
		echo "<h2 align='middle'>CADASTRO CONCLU�DO! Todos os dados est�o corretos!</h2>";
	}
?>