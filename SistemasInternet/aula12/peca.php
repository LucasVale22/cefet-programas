<?php

abstract class Peca
{
	public $nome = "";

	public function __construct($nome)
	{
		$this->nome = $nome;
	}

	public abstract function calculaPreco();

	public function mostraDados()
	{
		echo "Nome da Peça....: " . $this->nome . "\n";
		echo "Preço...........: " . $this->calculaPreco() . "\n";
	}
}

class PecaSimples extends Peca
{

	public $preco;

	public function __construct($nome, $preco)
	{
		parent::__construct($nome);
		$this->preco = $preco;
	}

	public function calculaPreco()
	{
#		echo "\nEstou calculando preco da peca " . $this->nome;
		return $this->preco;
	}

}

class PecaComposta extends Peca
{
	public $custoMontagem;
	public $composicao = array();

	public function __construct($nome, $custoMontagem)
	{
		parent::__construct($nome);
		$this->custoMontagem = $custoMontagem;
	}

	public function adicionaPeca($p)
	{
		array_push($this->composicao,$p);
	}

	public function calculaPreco()
	{
#		echo "\nEstou calculando preco da peca " . $this->nome;
		$soma = $this->custoMontagem;
		foreach($this->composicao as $p)
		{
			$soma += $p->calculaPreco();
		}
		return $soma;
	}
}



$pc1 = new PecaComposta("pc1",5.0);

$pc1->adicionaPeca( new PecaSimples("ps1.1", 10.0 ) );
$x = new PecaSimples("ps1.2", 20.0 );
$pc1->adicionaPeca( $x );
$pc1->adicionaPeca( new PecaSimples("ps1.3", 5.0 ) );
$pc1->adicionaPeca( new PecaSimples("ps1.4", 6.0 ) );


$pc2 = new PecaComposta("pc2",5.0);

$pc2->adicionaPeca( new PecaSimples("ps2.1", 10.0 ) );
$x = new PecaSimples("ps2.2", 20.0 );
$pc2->adicionaPeca( $x );
$pc2->adicionaPeca( new PecaSimples("ps2.3", 5.0 ) );
$pc2->adicionaPeca( new PecaSimples("ps2.4", 6.0 ) );

# $pc2->adicionaPeca( new Peca("XXXX") );

$pc2->adicionaPeca( $pc1 );

echo $pc2->mostraDados();

