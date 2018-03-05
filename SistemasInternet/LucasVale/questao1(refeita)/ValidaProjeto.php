<?php
	$resp=0;
	//TÍTULO
	$titproj=$_REQUEST["titproj"];
	$tit_no_espace=trim($titproj," ");
	if(strlen($tit_no_espace)>40 || strlen($tit_no_espace)<20 && strlen($tit_no_espace)>0 ){
		echo "</br>O Título do Projeto deve possuir entre 20 e 40 carateres!</br>";
		$resp++;
	}
	else{
		if(strlen($tit_no_espace)==0){
			echo "</br>O campo [Título do Projeto] é obrigatório!</br>";
			$resp++;
		}
	}
	
	//DESCRIÇÃO
	$descricao=$_REQUEST["descricao"];
	if(strlen($descricao)>2000){
		echo "</br>O campo [Descrição] deve possuir no máximo, 2000 caracteres!</br>";
		$resp++;
	}

	//DATA DE INÍCIO
	$dinicio=$_REQUEST["dinicio"];
	$barra1=substr($dinicio,2,1);
	$barra2=substr($dinicio,5,1);
	if(strlen($dinicio)==0)
	{
			echo "</br>O campo [Data de Início] é obrigatório!</br>";
			$resp++;
	}
	else{
		if(($barra1!="/")||($barra2!="/"))
		{
			echo "<br>A data de início deve estar no formato DD/MM/AAAA!</br>";
			$resp++;
		}
		else{
			$di=substr($dinicio,0,2);
			$mi=substr($dinicio,3,2);
			$ai=substr($dinicio,6,4);
			$dinicio=$ai.$mi.$di;
		}
	}
	//DATA DE TÉRMINO
	$dtermino=$_REQUEST["dtermino"];
	if(strlen($dtermino)!=0)
	{
		$barra1=substr($dtermino,2,1);
		$barra2=substr($dtermino,5,1);
		if(($barra1!="/")||($barra2!="/"))
		{
			echo "<br>A data de término deve estar no formato DD/MM/AAAA!</br>";
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
				echo "</br>A data de término deve ser posterior à de início!</br>";
				$resp++;
			}
		}
	}
	
	//EMAIL DO RESPONSÁVEL
	$email=$_REQUEST["email"];
	if(strlen($email)==0)
	{
		echo "</br>O campo[Email do Responsável] é obrigatório!</br>";
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
			echo "</br>O campo [Email do Responsável] está incorreto! Não pode haver o símbolo [@] como 1º caracter.</br> ";
			$resp++;
		}
		else
		{
			if($cont==0)
			{
				echo "</br>O campo [Email do Responsável] deve possuir o símbolo [@]!</br>";
				$resp++;
			}
			else
			{
				if($cont!=1)
				{
					echo "</br>O campo [Email do Responsável] está incorreto! Existe(m) mais de um símbolo [@].</br>";
					$resp++;
				}
			}
		}
	}
	//Se todos os campos estiverem corretos...
	if($resp==0)
	{
		echo "<h2 align='middle'>CADASTRO CONCLUÍDO! Todos os dados estão corretos!</h2>";
	}
?>