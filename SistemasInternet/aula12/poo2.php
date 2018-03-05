<?php

        class Pessoa
        {

                public $nome = "";
                public $email = "";

                public function __construct($nome,$email)
                {
                        $this->nome = $nome;
                        $this->email = $email;
                }

                public function mostraDados()
                {
                        echo $this->nome;
                        echo "\n";
                        echo $this->email;
                        echo "\n";
                }

        }


        class Aluno extends Pessoa
        {
                public $curso = "";

                public function __construct($nome,$email,$curso)
                {
                        parent::__construct($nome,$email);
                        $this->curso = $curso;
                }

                public function mostraDados()
                {
                        echo "-----------------------------------------------------\n";
                        parent::mostraDados();
                        echo $this->curso;
                        echo "\n";
                }

        }

        class Professor extends Pessoa
        {
                public $formacao = "";

                public function __construct($nome,$email,$formacao)
                {
                        parent::__construct($nome,$email);
                        $this->formacao = $formacao;
                }

                public function mostraDados()
                {
                        echo "-----------------------------------------------------\n";
                        parent::mostraDados();
                        echo $this->formacao;
                        echo "\n";
                }

        }

        class Disciplina
        {
                public $nome;
                public $professor;
                public $alunos = array();

                public function __construct($nome,$professor)
                {
                        $this->nome = $nome;
                        $this->professor = $professor;
                }

                public function matriculaAluno($aluno)
                {
                        array_push($this->alunos, $aluno);
                }

                public function imprimeDiario()
                {
                        echo "{$this->nome}\n";
                        echo "{$this->professor->nome}\n";
                        foreach($this->alunos as $a)
                        {
                                echo "{$a->nome}\n";
                        }
                }

        }



$p = new Professor("Fulano","Fulano@xpto","Ciencia");
# $p->mostraDados();

$d = new Disciplina("POO",$p);

for($i=0; $i<10; $i++)
{
        $a = new Aluno("AA $i","bb","info");
        $d->matriculaAluno($a);
}

$d->imprimeDiario();

/*
$v = array( $a, $p, $a, $a, $p );

foreach( $v as $k )
{
        $k->mostraDados();
}

/*
for($i=0; $i<5; $i++)
{
        $k = $v[i];
        $k->mostraDados();
}
*/
/*
function f(&$s)
{
        $s = new Pessoa();
        $s->nome = "xxx";
}

$p = new Pessoa();
$p->nome = "Fulano";

$q = new Pessoa();
$q->nome = "Beltrano";

$r = $p;
$r->nome = "Siclano";

// echo $p->nome;

f($p);
echo $p->nome;

*/