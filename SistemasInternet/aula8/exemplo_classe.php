<?php
	class Aluno{
		public $nome="";
		public $matricula="";
		public $email="";
		public $curso="";
		function mostraDados(){
			echo $this->nome;
		}
	}
	$a=new Aluno();
	$a->nome="fulano";
	$a->mostraDados();
?>