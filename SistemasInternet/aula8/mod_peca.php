<?php
	abstract class Peca{
		public $descricao="";
		abstract function calculaPreco();
		function mostraDados(){
			echo $this->descricao;
			echo $this->calculaPreco();
		}
	}
	class PecaSimples extends Peca{
		public $preco;
		function calculaPreco(){
			return $this->preco;
		}
	}
	class PecaComposta extends Peca{
		public $custoMontagem=50;
		public $composicao=array();
		function adicionaPeca($p){
			array_push($this->composicao,$p);	
		}
		function calculaPreco(){
			$soma=$this->custoMontagem;
			foreach($this->composicao as $p){
				$soma+=$p->calculaPreco(); //polimorfismo: ora pre�o da pe�a simples, ora pre�o da pe�a composta...
			}
			return $soma;
		}
	}
?>	
