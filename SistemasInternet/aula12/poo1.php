<?php
	class Pessoa
	{
		public $nome="";
		public $email="";
		
		public function mostraDados()
		{
			echo $this->nome;
			echo "\n";
			echo $this->email;
		}
	$p=new Pessoa();
	$p->nome="fulano";
	$q=new Pessoa();
	$q->nome="beltrano";
	$r=$p; //$r referencia ao mesmo objeto que $p
	$r->nome="siclano";
	echo $p->nome;
	

	
?>