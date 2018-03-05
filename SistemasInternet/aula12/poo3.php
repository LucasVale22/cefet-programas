<?php
	//abstract indica que a classe Peca não é instanciável, ou seja, neste caso somente as subclasses podem ser instanciadas
	class abstract Peca 
	{
		public $nome="";
		public __construct($nome)
		{
			$this->nome=$nome;
		}
		public abstract function  calculaPreco();
		public function mostraDados()
		{
			echo "Nome...:".$this->nome;
			echo "Preço..:".$this->calculaPreco();
		}
	}
	
	class PecaSimples extends Peca
	{
		public $preco;
		public function __construct($nome,$preco)
		{
			parent::__construct($nome);
			$this->preco=$preco;
		}
		function calculaPreco()
		{
			return $this->preco;
		}
	}
	
	class PecaComposta extends Peca
	{
		public $custoMontagem;
		public $composicao=array();
		public function __construct($nome,$custoMontagem)
		{
			parent::__construct($nome);
			$this->custoMontagem=$custoMontagem;
		}
		function adicionaPeca($p)
		{
			array_push($this->composicao,$p);
		}
		function calculaPreco()
		{
			$soma=$this->custoMontagem;
			foreach($this->composicao as $p)
			{
				$soma+=$p->calculaPreco(); //polimorfismo: ora preço da peça simples, ora preço da peça composta...
			}
			return $soma;
		}	
	}
	
	$pc1=new PecaComposta("pc1",5.0);
	$pc1->adicionaPeca(new PecaSimples("ps1.1",10.0));
	$pc1->adicionaPeca(new PecaSimples("ps1.2",20.0));
	$pc1->adicionaPeca(new PecaSimples("ps1.3",5.0));
	$pc1->adicionaPeca(new PecaSimples("ps1.4",6.0));
	
	$pc2=new PecaComposta("pc2",5.0);
	$pc1->adicionaPeca(new PecaSimples("ps2.1",10.0));
	$pc1->adicionaPeca(new PecaSimples("ps2.2",20.0));
	$pc1->adicionaPeca(new PecaSimples("ps2.3",5.0));
	$pc1->adicionaPeca(new PecaSimples("ps2.4",6.0));
	
	$pc2->adiciona($pc1);
	
	echo $pc2->mostraDados();
	
?>