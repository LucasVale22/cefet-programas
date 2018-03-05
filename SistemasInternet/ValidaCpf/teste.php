<?php
	$nome=$_REQUEST["nome"];
	if (strlen($nome)<10){
		echo "Nome muito curto<br />";
	}
		
	$cpf=$_REQUEST["cpf"];
	
	function calculadvcpf($cpf){
		$soma=0;
		$soma2=0;
		for($i=0; $i<strlen($cpf); $i++){
			$c=$cpf[$i];
			$soma+=$c*($i+1);
			$soma2+=$c*$i;
		}
		$dv1=$soma%11;
		if($dv1==10){
			$dv1=0;
		}
		$soma2+=$dv1*9;
		$dv2=$soma2%11;
		if($dv2==10){
			$dv2=0;
		}
		return "$dv1$dv2";
	
	}
	
	function validacpf($cpf){
		$x=substr($cpf,0,9);
		$dv=calculadvcpf($x);
		return $dv==substr($cpf,9,2);
	}
	if (validacpf($cpf)!=1){
		echo "CPF Inválido<br />";
	}
	
	$email=$_REQUEST["email"];
	for($i=0;$i<strlen($email); $i++){
		$c=$email[$i];
		if(($i==0)&&($c=='@')){
			echo "Email Invalido<br />";
		}
	}
		if($c=='@'){
			echo "Email Invalido<br />";
		}
		
	$tel=$_REQUEST["tel"];
	if ((strlen($tel)>0)&&(strlen($tel)!=8)){
		echo "Telefone Incorreto<br />";
	}
	
	if ((strlen($tel)==0) && (strlen($email)==0)){
		echo "Preencha pelo menos um dos dois campos: Email/Telefone<br />";
	}
	echo "Se essa for a única mensagem exibida, o formulário foi preenchido com sucesso.";
	
	

?>                  
 