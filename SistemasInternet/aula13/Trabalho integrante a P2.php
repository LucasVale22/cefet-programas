<?php
	/*Interface mostrar ()
	{
		public function mostra_dados();
	}
	*/
    abstract class Pessoa
	{
		public $nome;
		public $idade;
		public $email;
		function __construct($nome,$idade,$email)
		{
			$this->nome=$nome;
			$this->idade=$idade;
			$this->email=$email;
		}
	}
	class Professor extends Pessoa //implements mostrar
	{
		public $espc;
		public $displinas=array();
		public function __construct($nome,$idade,$email,$espc)
		{
			parent::__construct($nome,$idade,$email);
			$this->espc=$espc;
			$CEFET->add_prof($this);
		}
		public function add_disc($disciplina)
		{
			array_push($this->disciplinas,$disciplina);
		}
		public function mostra_dados()
		{
			echo $this->nome,$this->idade,$this->email,$this->espc;
			foreach($disciplinas as $d)
			echo "<a href='?'";
		}
	}
	abstract class Aluno extends Pessoa //Implements mostrar
	{
		public $matricula;
		public $disciplinas=array();
		public function add_disc($disciplina)
		{
			array_push($this->disciplinas,$disciplina);
		}
		public function __construct($nome,$idade,$email,$curso,$matricula)
		{
			parent::__construct($nome,$idade,$email);
			$this->curso=$curso;
			$this->matricula=$matricula;
		}
		
		public function mostra_dados()
		{
			echo "$this->nome, $this->idade, $this->email, $this->matricula,";
			foreach($disciplinas as $d)
			echo "$d->mostra_dados(),";
		}
	}
	class Tecnico extends Aluno 
	{
		public function __construct($nome,$idade,$email,$matricula)
		{
			parent::__construct($nome,$idade,$email,$matricula);
			$CEFET->add_aluno_tec($this);
			
		}		
	}
	class Superior extends Aluno
	{
		public function __construct($nome,$idade,$email,$matricula)
		{
			parent::__construct($nome,$idade,$email,$matricula);
			$CEFET->add_aluno_sup($this);
			
		}
	}
	class Escola //implements mostrar
	{
		public $nome;
		public $professores=array();
		public $aluno_tec=array();
		public $aluno_sup=array();
		public $turmas=array();
		public function __construct($nome)
		{
			$this->nome=$nome;
		}
		public function add_prof($professor)
		{
			array_push($this->professores,$professor);
		}
		public function add_aluno_tec($aluno)
		{
			array_push($this->aluno_tec,$aluno);
		}
		public function add_aluno_sup($aluno)
		{
			array_push($this->aluno_sup,$aluno);
		}
		public function add_turma($turma)
		{
			array_push($this->turmas,$turma);
		}
		public function mostra_dados()
		{
			echo "$nome,";
			foreach($turmas as $t)
			echo "$t,";
			foreach ($professores as $p)
			echo"$p,";
			foreach ($aluno_tec as $at)
			echo"$at,";
			foreach($aluno_sup as $as)
			echo"$as,";
		}
	}
	class Disciplina //implements mostrar
	{
		public $turmas=array();
		public function add_turma($turma)
		{
			array_push($this->turmas,$turma);
		}
		public function mostra_dados()
		{
		}
	}
	class Turma implements mostrar
	{
		public $professor;
		public $alunos=array();
		public $disciplina;
		function __construct($professor,$disciplina)
		{
			$this->professor=$professor;
			$this->disciplina=$disciplina;
			$CEFET->add_turma($this);
		}
		public function add_aluno($aluno)
		{
			array_push($this->alunos,$aluno);
		}
		public function mostra_dados()
		{
		}
	}
	$CEFET= new Escola("CEFET-RJ");
	$al1= new Tecnico ("Diogo",17,"diogo1243","1001102MED");
	$al2= new Tecnico("Lula",18,"lukinhasleao","1001106MED");
	$al3= new Tecnico("Do Vale",17,"lukasvale22","1001237MED");
	$prof= new Professor ("Renato",20,"renato.mauro","Sistemas");
	$prof2= new Professor ("Brito",50,"@@@@@@","FERRAR OS ALUNOS");	
	$disc= new Disciplina ();
	$t= new Turma($prof,$disc);
	$disc->add_turma($t);
	$t->add_aluno($al1);
	$t->add_aluno($al2);
	$t->add_aluno($al3);
	$al4= new Superior ("FULANO",25,"#####","9999999SUP");
	$disc2= new Disciplina();
	$t2= new Turma($disc2);
	$al1->add_disc($disc);
	$al2->add_disc($disc);
	$al3->add_disc($disc);
	$al4->add_disc($disc2);
	$CEFET->mostra_dados();
	
?>	