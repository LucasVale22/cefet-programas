<?php
	class Pessoa{
		public $nome="";
		public $email="";
		function mostraDados(){
			echo $this->nome;
			echo $this->email;
		}
	}
	class Aluno extends Pessoa{
		public $matricula="";
		public $curso="";
		function mostraDados(){
			parent :: mostraDados(); //chama a funчуo mostraDados() da superclasse...
			echo $this->matricula;
			echo $this->curso;
		}
	}
	class Professor extends Pessoa{
		public $matricula="";
		public $especialidade="";
		function mostraDados(){
			parent :: mostraDados(); //chama a funчуo mostraDados() da superclasse...
			echo $this->matricula;
			echo $this->especialidade;
		}
	}
	$v=array();
	
	foreach($v as $a){
		$a->mostraDados();
	}	
?>