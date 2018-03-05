<?php
	/*Interface mostra_dados ()
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
		public $id;
		public $espc;
		public $disciplinas=array();
		public function __construct($id,$nome,$idade,$email,$espc)
		{
			parent::__construct($nome,$idade,$email);
			$this->espc=$espc;
			$this->id=$id;
		}
		public function add_disc($disciplina)
		{
			array_push($this->disciplinas,$disciplina);
		}
		public function mostra_dados()
		{
			echo "Nome: $this->nome</br>Idade: $this->idade</br>E-mail: $this->email</br>Especialidade: $this->espc</br>";
			foreach($this->disciplinas as $d)
			{
			echo "<a href='disc_prof.php?id=$d->id&idd=$this->id'>$d->nome</a>";
			echo "</br>";
			}
		}
	}
	abstract class Aluno extends Pessoa //implements mostrar
	{
		public $disciplinas=array();
		public function add_disc($disciplina)
		{
			array_push($this->disciplinas,$disciplina);
		}
		
		public abstract function mostra_dados();
		public function __contruct ($nome,$idade,$email)
		{
			parent::__construct ($nome,$idade,$email);
		}
	}
	class Tecnico extends Aluno 
	{
		public $id;
		public $matricula;
		public function __construct($id,$nome,$idade,$email,$matricula)
		{
			parent::__construct($nome,$idade,$email);
			$this->id=$id;	
			$this->matricula=$matricula;
		}	
		public function mostra_dados()
		{
			echo "Nome: $this->nome </br>" ;
			echo "Idade: $this->idade </br>";
			echo "E-mail: $this->email </br>";
			echo "Matricula: $this->matricula </br>";
			foreach($this->disciplinas as $d)
			echo "<a href='disc_al_tec.php?id=$d->id&idd=$this->id'>$d->nome</a>";
		}		
	}
	class Superior extends Aluno
	{
		public $id;
		public $matricula;
		public function __construct($id,$nome,$idade,$email,$matricula)
		{
			parent::__construct($nome,$idade,$email);
			$this->id=$id;
			$this->matricula=$matricula;
		}
		public function mostra_dados()
		{
			echo "Nome: $this->nome </br>" ;
			echo "Idade: $this->idade </br>";
			echo "E-mail: $this->email </br>";
			echo "Matricula: $this->matricula </br>";
			foreach($this->disciplinas as $d)
			echo "<a href='disc_al_sup.php?id=$d->id&idd=$this->id'>$d->nome</a>";
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
			echo 
			"
				<h1 style='text-align: center; font-family: Garamond,serif; line-height: 1em; color: #321f9c; font-weight:bold; font-size: 101px; text-shadow:0px 0px 0 rgb(11,-8,117),1px 1px 0 rgb(-4,-23,102),2px 2px 0 rgb(-20,-39,86),3px 3px 0 rgb(-36,-55,70),4px 4px 0 rgb(-52,-71,54),5px 5px 0 rgb(-67,-86,39),6px 6px 0 rgb(-83,-102,23),7px 7px 0 rgb(-99,-118,7), 8px 8px 0 rgb(-115,-134,-9),9px 9px 8px rgba(0,0,0,1),9px 9px 1px rgba(0,0,0,0.5),0px 0px 8px rgba(0,0,0,.2);'>$this->nome</h1></br>
				<table style='margin-right:auto; margin-left:auto; font-family: Agency FB; font-size: 30px; '>
					<tr>
						<td><a href=v_turma.php>Turmas</a></td>
						<td><a href=v_prof.php>Professores</a></td>
						<td><a href=v_al_tec.php>Alunos Técnicos</a></td>
						<td><a href=v_al_sup.php>Alunos Superiores</a></td>
					</tr>
				</table>
			";
		}
	}
	class Disciplina //implements mostrar
	{
		public $nome;
		public $id;
		public $turmas=array();
		function __construct($id,$nome)
		{
			$this->id=$id;
			$this->nome=$nome;
		}
		public function add_turma($turma)
		{
			array_push($this->turmas,$turma);
		}
		public function mostra_dados()
		{
			echo "Nome: $this->nome </br>";
			foreach ($this->turmas as $t)
			{
				echo "<a href=\"turma.php?id=$t->id\">$t->nome</a></br>";
			}
		}
	}
	class Turma //implements mostrar
	{
		public $id;
		public $nome;
		public $professor;
		public $alunos=array();
		public $disciplina;
		public $tipo;
		public $cont=0;
		function __construct($id,$nome,$professor,$disciplina,$tipo)
		{
			$this->id=$id;
			$this->nome=$nome;
			$this->professor=$professor;
			$this->disciplina=$disciplina;
			$this->tipo=$tipo;
		}
		public function add_aluno($aluno)
		{
			array_push($this->alunos,$aluno);
		}
		public function mostra_dados()
		{
			global $CEFET;
			echo "Nome: $this->nome</br>";
			echo"Tipo: $this->tipo</br>";
			echo "Professor: </br>";
			$p=$this->professor;
			echo "<a href=\"professor.php?id=$p->id\">$p->nome</a></br>";
			if ($this->tipo=="tecnico")
			{
			echo "Alunos Técnico: </br>";
			foreach ($this->alunos as $at)
			{
			echo "<a href=\"aluno_tec.php?id=$at->id\">$at->nome</a></br>";
			$cont++;
			}
}			if ($this->tipo=="superior")
			{
			echo "Alunos Superior </br>";
			foreach ($this->alunos as $at)
			{
			echo "<a href=\"aluno_sup.php?id=$at->id\">$at->nome</a></br>";
			}
			}
		}
	}
	class Creator 
	{
		public function Novo_Aluno_Tec(&$aluno,$id,$nome,$idade,$email,$matricula)
		{
			global $CEFET;
			$aluno=new Tecnico($id,$nome,$idade,$email,$matricula);
			$CEFET->add_aluno_tec($aluno);			
		}
		public function Novo_Prof(&$Professor,$id,$nome,$idade,$email,$matricula)
		{
			global $CEFET;
			$Professor=new Professor($id,$nome,$idade,$email,$matricula);
			$CEFET->add_prof($Professor);
		}
		public function Novo_Aluno_Sup(&$aluno,$id,$nome,$idade,$email,$matricula)
		{
			global $CEFET;
			$aluno=new Superior($id,$nome,$idade,$email,$matricula);
			$CEFET->add_aluno_sup($aluno);
		}
		public function Novo_Turma (&$turma,$id,$nome,$professor,$disciplina,$tipo)
		{
			global $CEFET;
			$turma=new Turma ($id,$nome,$professor,$disciplina,$tipo);
			$CEFET->add_turma($turma);
		}
	}
	function view($string)
	{
		global $CEFET;
		if ($string=="Alunos_Tec")
		{
			echo "Alunos Técnico: </br>";
			foreach ($CEFET->aluno_tec as $at)
			{
			echo "<a href=\"aluno_tec.php?id=$at->id\">$at->nome</a></br>";
			}
		}
		if ($string=="Alunos_Sup")
		{
			echo "Alunos Superior: </br>";
			foreach($CEFET->aluno_sup as $as)
			echo "<a href=\"aluno_sup.php?id=$as->id\">$as->nome</a></br>";
		}
		if ($string=="Professores")
		{
			echo "Professores: </br>";
			foreach ($CEFET->professores as $p)
			echo "<a href=\"professor.php?id=$p->id\">$p->nome</a></br>";
		}
		if ($string=="Turmas")
		{
			echo "Turmas: </br>";
			foreach($CEFET->turmas as $t)
			echo "<a href=\"turma.php?id=$t->id\">$t->nome</a></br>";
		}
	}
	$CEFET= new Escola("CEFET-RJ");
	$creator=new Creator();
	
	//Alunos técnico
	$creator->Novo_Aluno_Tec($al1,1,"Airton da Silva Carvalho Junior",17,"super_airtonjr@hotmail.com","1000121MED");
	$creator->Novo_Aluno_Tec($al2,2,"Aline Lopes Xavier",19,"kono_7@freak.la","1000122MED");
	$creator->Novo_Aluno_Tec($al3,3,"Christiano Benicio Pinto",18,"christianomade@hotmail.com","1001235MED");
	$creator->Novo_Aluno_Tec($al4,4,"Diogo Nocera Magalhães",17,"diogo1243@gmail.com","1000102MED");
	$creator->Novo_Aluno_Tec($al5,5,"Gabriel Corte Real Saldanha",17,"gabrielcrsaldanha@hotmail.com","1081102MED");
	$creator->Novo_Aluno_Tec($al6,6,"Gabriel Passarelli Gomes",17,"gabriel_passarelli_gomes@hotmail.com","7701106MED");
	$creator->Novo_Aluno_Tec($al7,7,"Gabriel de Souza Barbosa",18,"gs_rock13@hotmail.com","1006506MED");
	$creator->Novo_Aluno_Tec($al8,8,"Giovanni Luiz Alves Pereira",17,"giovanni_luiz95@hotmail.com","1201237MED");
	$creator->Novo_Aluno_Tec($al9,9,"Hyury Duarte Silva",17,"hyury_rj@hotmail.com","1001023MED");
	$creator->Novo_Aluno_Tec($al10,10,"Igor Martire de Miranda",17," igorx94@gmail.com","1001106MED");
	$creator->Novo_Aluno_Tec($al11,11,"Juliana Jalloule Pessoa",17,"juuh.potter_stroonda@hotmail.com","1077106MED");
	$creator->Novo_Aluno_Tec($al12,12,"Kaique Batista Barbosa",18,"k_a_i_q_u_e@hotmail.com","1001238MED");
	$creator->Novo_Aluno_Tec($al13,13,"Leonardo Betzler Rodrigues",18,"leo.betzler@hotmail.com","1023445MED");
	$creator->Novo_Aluno_Tec($al14,14,"Leonardo Ramos Almeida",18,"rutrisline@bol.com.br","1001134MED");
	$creator->Novo_Aluno_Tec($al15,15,"Lucas do Vale Santos",17,"lukasvale22gmail.com","1001237MED");
	$creator->Novo_Aluno_Tec($al16,16,"Lucas Leão Feitosa",17,"lukinhasleao@hotmail.com","1001121MED");
	$creator->Novo_Aluno_Tec($al17,17,"Lucas Teixeira Barbeiro",17,"lucas_teixeira_barbeiro@hotmail.com","1001247MED");
	$creator->Novo_Aluno_Tec($al18,18,"Matheus Bottino Maciel",17,"m1bottino@hotmail.com","1001101MED");
	$creator->Novo_Aluno_Tec($al19,19,"Natalia Ramos da Conceição",18,"nataliaramos.09@hotmail.com","1034106MED");
	$creator->Novo_Aluno_Tec($al20,20,"Nelson Pitanga Lachini",18,"nelsonlachini@gmail.com","10016637MED");
	$creator->Novo_Aluno_Tec($al21,21,"Patricia de Andrade Kovaleski",17,"patriciakovaleski@hotmail.com","1333456MED");
	$creator->Novo_Aluno_Tec($al22,22,"Thamirys Rosa de Souza",17,"thamirysrosa@hotmail.com","2004001MED");
	
	
	$creator->Novo_Prof($prof1,1,"Renato Mauro",20,"renato.mauro@gmail.com","Espc1");
	$creator->Novo_Prof($prof2,2,"Laercio Brito",35,"laerciobr@gmail.com","Espc2");
	$creator->Novo_Prof($prof3,3,"Laercio Dantas",56,"dantas_lr@yahoo.com","Espc3");
	$creator->Novo_Prof($prof4,4,"Jorge Soares",34,"jorge_soares@yahoo.com","Espc4");
	$creator->Novo_Prof($prof5,5,"Celso Afonso",71,"celafonso@hotmail.con","Espc5");
	$creator->Novo_Prof($prof6,6,"Fábio Junior",44,"fb.junior@gmail.com","Espc6");
	$creator->Novo_Prof($prof7,7,"Myrna Amorim",23,"myrnaamr@gmail.com","Espc7");
	$creator->Novo_Prof($prof8,8,"Luiz Amaral",60,"luiz_amaral@yahoo.com","Espc8");	
	
	
	$disc1= new Disciplina (1,"Sistema Internet");
	$disc2= new Disciplina (2,"Estrutura de Dados");
	$disc3= new Disciplina (3,"Eletrônica e Hardware");
	$disc4= new Disciplina (4,"Banco de Dados I");
	$disc5= new Disciplina (5,"Disciplina Indefinida");
	$disc6= new Disciplina (6,"Engenharia Software");
	$disc7= new Disciplina (7,"Desenvolvimento Web");
	$disc8= new Disciplina (8,"Projeto de Redes I");
	
	
	$creator->Novo_Turma($t1,1,"INFO00",$prof1,$disc1,"tecnico");
	$creator->Novo_Turma($t2,2,"INFO01",$prof2,$disc2,"tecnico");
	$creator->Novo_Turma($t3,3,"INFO10",$prof3,$disc3,"tecnico");
	$creator->Novo_Turma($t4,4,"INFO11",$prof4,$disc4,"tecnico");
	$creator->Novo_Turma($t5,5,"INFO02",$prof5,$disc5,"tecnico");
	$creator->Novo_Turma($t6,6,"INFO20",$prof6,$disc6,"tecnico");
	$creator->Novo_Turma($t7,7,"INFO22",$prof7,$disc7,"tecnico");
	$creator->Novo_Turma($t8,8,"INFO12",$prof8,$disc8,"tecnico");
	
	
	$disc1->add_turma($t1);
	$disc2->add_turma($t2);
	$disc3->add_turma($t3);
	$disc4->add_turma($t4);
	$disc5->add_turma($t5);
	$disc6->add_turma($t6);
	$disc7->add_turma($t7);
	$disc8->add_turma($t8);
	
	
	$t1->add_aluno($al1);
	$t1->add_aluno($al2);
	$t1->add_aluno($al3);
	$t2->add_aluno($al4);
	$t2->add_aluno($al5);
	$t2->add_aluno($al6);
	$t3->add_aluno($al7);
	$t3->add_aluno($al8);
	$t3->add_aluno($al9);
	$t4->add_aluno($al10);
	$t4->add_aluno($al11);
	$t4->add_aluno($al12);
	$t5->add_aluno($al13);
	$t5->add_aluno($al14);
	$t6->add_aluno($al15);
	$t6->add_aluno($al16);
	$t6->add_aluno($al17);
	$t7->add_aluno($al18);
	$t7->add_aluno($al19);
	$t8->add_aluno($al20);
	$t8->add_aluno($al21);
	$t8->add_aluno($al22);
	
	
	$al1->add_disc($disc1);
	$al2->add_disc($disc1);
	$al3->add_disc($disc1);
	$al4->add_disc($disc2);
	$al5->add_disc($disc2);
	$al6->add_disc($disc2);
	$al7->add_disc($disc3);
	$al8->add_disc($disc3);
	$al9->add_disc($disc3);
	$al10->add_disc($disc4);
	$al11->add_disc($disc4);
	$al12->add_disc($disc4);
	$al13->add_disc($disc5);
	$al14->add_disc($disc5);
	$al15->add_disc($disc6);
	$al16->add_disc($disc6);
	$al17->add_disc($disc6);
	$al18->add_disc($disc7);
	$al19->add_disc($disc7);
	$al20->add_disc($disc8);
	$al21->add_disc($disc8);
	$al22->add_disc($disc8);
	
	
	$prof1->add_disc($disc1);
	$prof2->add_disc($disc2);
	$prof3->add_disc($disc3);
	$prof4->add_disc($disc4);
	$prof5->add_disc($disc5);
	$prof6->add_disc($disc6);
	$prof7->add_disc($disc7);
	$prof8->add_disc($disc8);
	
	
	//Alunos superior
	$creator->Novo_Aluno_Sup($al50,51,"Adailton Silveira Gomes",22,"ada.gom@gmail.com","9994440SUP");
	$creator->Novo_Aluno_Sup($al51,52,"Anália de Souza Braga",19,"braganalia@yahoo.com","3847566SUP");
	$creator->Novo_Aluno_Sup($al52,53,"Brenda Araújo da Costa",20,"brenda12araujo@yahoo.com","1232343SUP");
	$creator->Novo_Aluno_Sup($al53,54,"Cecília Meireles Martins",21,"cecilia234rj@hotmail.com","9998668SUP");
	$creator->Novo_Aluno_Sup($al54,55,"Daniel Nocera Assunção",19,"daniel_10_ass@hotmail.com","1110320SUP");
	$creator->Novo_Aluno_Sup($al55,56,"Hugo Pimentel Cardoso",19,"huguinho.ptel@gmail.com","3356682SUP");
	$creator->Novo_Aluno_Sup($al56,57,"Jandira Alves da Cunha",20,"jaalc77@yahoo.com","1111113SUP");
	$creator->Novo_Aluno_Sup($al57,58,"Lady Hannah do Vale",22,"lady_h_dovale@gmail.com","8797777SUP");
	$creator->Novo_Aluno_Sup($al58,59,"Larissa Augusto Leão ",23,"lala.leao001@hotmail.com","2222224SUP");
	$creator->Novo_Aluno_Sup($al59,60,"Renan Siqueira Campos",21,"re.siqueira@bol.com.br","19898987SUP");
	$creator->Novo_Aluno_Sup($al60,61,"Valena dos Santos Mendes",19,"valena_santos45@yahoo.com","4345676SUP");
	$creator->Novo_Aluno_Sup($al61,62,"Zacarias Venâncio Passarelli ",22,"passarellizac@hotmail.com","1444446SUP");
	
	
	
	$creator->Novo_Prof($prof25,31,"Ivan Monteiro",45,"ivanmonteiro@gmail.com","Espc100");
	$creator->Novo_Prof($prof26,32,"Isaque Cardoso",56,"isaque.cardoso@gmail.com","Espc200");
	$creator->Novo_Prof($prof27,33,"Tereza Fachada",58,"tereza_f12@yahoo.com","Espc300");
	$creator->Novo_Prof($prof28,34,"Marcelo Chaves",40,"marceloch34@yahoo.com","Espc400");
	$creator->Novo_Prof($prof29,35,"Mirian Azevedo",47,"azevedo_mirian@hotmail.con","Espc500");
	$creator->Novo_Prof($prof30,36,"Creppe Medeiros",34,"creppe100.med@gmail.com","Espc600");
	$creator->Novo_Prof($prof31,37,"Gepeto Fantonni",49,"gepeto_fantonni.com","Espc700");
	$creator->Novo_Prof($prof32,38,"Paulo Borges",89,"pb_fisica_1000@yahoo.com","Espc800");	
	
	
	$disc31= new Disciplina (31,"Álgebra Relacional");
	$disc32= new Disciplina (32,"Químico-Física");
	$disc33= new Disciplina (33,"História da Arte");
	$disc34= new Disciplina (34,"Cálculo III");
	$disc35= new Disciplina (35,"Programação Genética");
	$disc36= new Disciplina (36,"Química Experimental");
	$disc37= new Disciplina (37,"Física II");
	$disc38= new Disciplina (38,"Física XX");
	
	
	$creator->Novo_Turma($t31,31,"ALG00",$prof25,$disc31,"superior");
	$creator->Novo_Turma($t32,32,"QUI01",$prof26,$disc32,"superior");
	$creator->Novo_Turma($t33,33,"HIS11",$prof27,$disc33,"superior");
	$creator->Novo_Turma($t34,34,"CALC03",$prof28,$disc34,"superior");
	$creator->Novo_Turma($t35,35,"PG00",$prof29,$disc35,"superior");
	$creator->Novo_Turma($t36,36,"QUI02",$prof30,$disc36,"superior");
	$creator->Novo_Turma($t37,37,"FIS02",$prof31,$disc37,"superior");
	$creator->Novo_Turma($t38,38,"FIS20",$prof32,$disc38,"superior");
	
	
	$disc31->add_turma($t31);
	$disc32->add_turma($t32);
	$disc33->add_turma($t33);
	$disc34->add_turma($t34);
	$disc35->add_turma($t35);
	$disc36->add_turma($t36);
	$disc37->add_turma($t37);
	$disc38->add_turma($t38);
	
	
	$t31->add_aluno($al50);
	$t31->add_aluno($al51);
	$t32->add_aluno($al52);
	$t32->add_aluno($al53);
	$t33->add_aluno($al54);
	$t33->add_aluno($al55);
	$t34->add_aluno($al56);
	$t34->add_aluno($al57);
	$t35->add_aluno($al58);
	$t36->add_aluno($al59);
	$t37->add_aluno($al60);
	$t38->add_aluno($al61);
	
	
	$al50->add_disc($disc31);
	$al51->add_disc($disc31);
	$al52->add_disc($disc32);
	$al53->add_disc($disc32);
	$al54->add_disc($disc33);
	$al55->add_disc($disc33);
	$al56->add_disc($disc34);
	$al57->add_disc($disc34);
	$al58->add_disc($disc35);
	$al59->add_disc($disc36);
	$al60->add_disc($disc37);
	$al61->add_disc($disc38);
	
	
	$prof25->add_disc($disc31);
	$prof26->add_disc($disc32);
	$prof27->add_disc($disc33);
	$prof28->add_disc($disc34);
	$prof29->add_disc($disc35);
	$prof30->add_disc($disc36);
	$prof31->add_disc($disc37);
	$prof32->add_disc($disc38);
	
	echo 
	"
		<style type='text/css'>
				<!--
				body
				{
					background-image: url('fundo1.jpg');
					-moz-background-size: 100% 100%;
					-webkit-background-size: 100% 100%;
					background-size: 100% 100%;
					background-attachment: fixed;
					background-repeat: no-repeat;
				}
				-->
		</style>
	";
	
?>	