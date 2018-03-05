<?php
	class Pessoa{
		public $nome;
		public $idade;
		public function __construct($nome,$idade=10){ //inverso de __destruct...
			$this->nome=$nome;
			$this->idade=$idade;
		}
		public function __destruct(){
			echo "{$this->nome} morreu aos {$this->idade} anos! ";  //desaloca "magicamente" o endereço de memória alocada...
		}
	}
	$p=new Pessoa("fulano");
	$q=new Pessoa("Beltrano",20);
	$r=new Pessoa(20);
?>