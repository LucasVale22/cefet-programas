<?php
	class Pessoa{
		public $nome;
		public $idade;
		public function __construct($nome,$idade=10){ 
			$this->nome=$nome;
			$this->idade=$idade;
		}
		public function __destruct(){
			echo " {$this->nome} tem {$this->idade} anos. ";  
		}
	}
	class Aluno extends Pessoa{
		public function __construct($nome,$idade=15){
			parent::__construct($nome,$idade);
			echo " Sou Aluno! ";
		}
		public function __destruct(){
			echo " tchau Aluno ";
		}
	}
	$p=new Pessoa("fulano");
	$q=new Aluno("beltrano");
	$p=null;
	$q=null;
?>