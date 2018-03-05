<?php
abstract class Pessoa
{
	public $nome;
	public $email;
	public function __construct($nome,$email)
	{
		$this->nome=$nome;
		$this->email=$email;
	}
}

class Aluno extends Pessoa
{
	public $matricula;
	public $curso;
	public function __construct($nome,$email,$matricula,$curso)
	{
		parent::__construct($nome,$email);
		$this->matricula=$matricula;
		$this->curso=$curso;
	}
}

class Professor extends Pessoa
{
	public $especialidade;
	public $disciplinas=array();
	public function __construct($nome,$email,$especialidade)
	{
		parent::__construct($nome,$email);
		$this->especialidade=$especialidade;
	}
	public function adicionaDisciplina($d)
	{
		array_push($this->disciplinas,$d);
	}
	public function removeDisciplina()
	{
		foreach($disciplinas as $key=>$x) //este key "pega" o índice do vetor que corresponde a $x....
		{
			if($x==$d)
			{
				$disciplinas[$key]=null;
			}
		}
	}
}
class Disciplina
{
	public $codigo;
	public $descricao;
	public $professor;
	public function __construct($codigo,$descricao)
	{
		$this->codigo=$codigo;
		$this->descricao=$descricao;
	}
	public function associaProfessor($p)
	{
		if($this->professor && $this->professor!=$p)
		{
			$this->professor->removeDisciplina($this);
		}
		$this->professor=$p;
		$p->adicionaDisciplina($this);
	}
}
class Inscricao
{
	public $p1;
	public $p2;
	public $faltas;
	public $inscricoes=array();
	public function inscreveAlunoDisciplina($i)
	{
		array_push($this->inscricoes,$i);
	}	
}
$d=new Disciplina("APBD","aplicação de BD");
$a1=new Aluno("1234","inf","fulano","fulano@gmail");
$a2=new Aluno("4567","inf","beltrano","beltrano@gmail");
$a3=new Aluno("8901","inf","ciclano","ciclano@gmail");
$p1=new Professor("PHP","renato.mauro@gmail","Renato");
$p2=new Professor("BD","jorge@pobox","Jorge");
$d->associaProfessor($p1);
$i=new Inscricao("fulano","aplicação de BD");
//o ideal é que não se manipule atributos de uma classe em uma outra classe...
//fazer a classe Inscricao....
//::parent é só para subclasse
?>
