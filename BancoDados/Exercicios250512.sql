create table ORGAO 
(
	cod_orgao	int	primary key, 
	nome_orgao	varchar(20)	not null
)
;
create table DEPARTAMENTO 
(
	cod_depto	int	not null, 
	localizacao	varchar(60),
	primary key (cod_depto),
	foreign key (cod_depto) references Orgao(cod_orgao)
)
;
create table DIVISAO 
(
	cod_div 	int	not null,
	primary key (cod_div),
	foreign key (cod_div) references Orgao(cod_orgao)
)
;
create table FUNCIONARIO 
(
	matricula	int		not null, 
	nome_func	varchar(60)	not null, 
	anos_servico	int, 
	salario		float, 
	cod_orgao	int,
	primary key (matricula),
	foreign key (cod_orgao) references orgao(cod_orgao)
)
;	
create table SUBORDINADO 
(
	cod_depto	int	not null, 
	cod_div		int	not null,
	primary key (cod_depto,cod_div),
	foreign key (cod_depto) references departamento(cod_depto),
	foreign key (cod_div) references divisao(cod_div)
)
;
create table GERENCIA 
(
	mat_ger		int	not null, 
	cod_orgao	int	not null,
	primary key (mat_ger, cod_orgao),
	foreign key (cod_orgao) references orgao(cod_orgao),
	foreign key (mat_ger) references funcionario(matricula)
)
;
create table FUNC_COMUM 
(
	mat_func	int 	not null,
	cargo		varchar(30),
	primary key (mat_func),
	foreign key (mat_func) references funcionario(matricula)
)
;
create table PROJETO 
(
	cod_proj	varchar(50)	not null, 
	nome_proj	int 	not null, 
	inicio		int, 
	fim		int,
	primary key (cod_proj)
)
;
create table ALOCA 
(
	cod_proj	int 	not null, 
	mat_func	int	not null, 
	data_alocacao	varchar(5),
	primary key (cod_proj, mat_func),
	foreign key (cod_proj) references projeto(cod_proj),
	foreign key (mat_func) references funcionario(matricula)
)
;
create table COORDENA 
(
	cod_projeto	int	not null, 
	mat_coord	int	not null, 
	data_alocacao	varchar(5),
	primary key (cod_projeto, mat_coord),
	foreign key (cod_projeto) references projeto(cod_proj),
	foreign key (mat_coord) references funcionario(matricula)
)
;
create table SUPERVISIONA 
(
	mat_superior	int not null, 
	mat_func	int not null,
	primary key (mat_superior, mat_func),
	foreign key (mat_superior) references funcionario(matricula),
	foreign key (mat_func) references funcionario(matricula)
)
;
create table PROJ_TECNICO 
(
	cod_proj	int not null, 
	area_pesquisa	varchar(80),
	primary key (cod_proj),
	foreign key (cod_proj) references projeto(cod_proj)
);

alter table Funcionario
add column CPF char(11);

alter table Funcionario
add constraint uq1 UNIQUE(CPF);


/*
	create table T
	( a integer not null,
	  b integer not null default 0,
	  c integer not null,
	  d integer );

	insert into T
	values (2,0,0,1),(3,7,7,2);

	insert into T(a,c)
	values (11,12);

	update T
	set c=5, d=8;

	update T
	set b=b+3
	where d=8;

	update T
	set c=2*c
	where a%2=0

	delete from T
	where c%2=1
	
	delete from T
	
	drop table T
*/
	
delete from funcionario;
delete from orgao;
delete from departamento;
delete from divisao;
delete from supervisiona;
delete from gerencia;


/*insert into orgao
values	(1, 'O1'),
	(2, 'O2'),
	(3, 'O3'),
	(4, 'O4'),
	(5, 'O5'),
	(6, 'O6'),
	(7, 'O7');

insert into departamento
values	(1,'Loc1'),
	(3,'Loc2'),
	(4,'Loc3'),
	(5,'Loc4');

insert into divisao
values	(2), (6), (7);

insert into funcionario
values	(1,'F1',1,100,3),
	(2,'F2',2,200,7),
	(3,'F3',3,300,5),
	(4,'F4',4,400,2),
	(5,'F5',5,500,4);

insert into supervisiona
values	(3,1),
	(2,4),
	(5,3),
	(5,2);

insert into gerencia
values	(1,6),(2,7),(4,1);*/


select *
from funcionario   --questao 1

select nome_func
from funcionario
where anos_servico>=10 and anos_servico<=12; --questao 2
/*comando alternativo: where anos_servico between 10 and 12*/

select nome_func,matricula,salario
from funcionario
where salario>3000 or salario<1000; --questao3

select nome_func
from funcionario
where anos_servico=5 or anos_servico=8 or anos_servico=13 or anos_servico=NULL; --questao 4
/*comando alternativo: where anos_servico in (5,8,13,null)*/

select nome
from funcionario     --questao 5
where nome like '_AN%' and nome like '_ON%';

select matricula,nome_func,salario
from funcionario     --questao 6
order by nome_func

select anos_servico,matricula,nome_func,salario
from funcionario
order by anos_servico desc,salario desc;      --questao 7

select o.nome_orgao,f.matricula,f.nome_func    --questao 8
from orgao o join departamento d on o.cod_orgao=d.cod_depto /*o e d são "apelidos" dados às tabelas orgao e departamento respectivamente*/
	join funcionario f on o.cod_orgao=f.cod_orgao	          /*join significa a junção de tabelas*/
order by o.nome_orgao,f.salario desc ;  

select f.nome_func,d.cod_div,o.nome orgao --questao 9
from funcionario f join gerencia g on f.matricula=g.mat_ger
	 join divisao d on g.cod_orgao=d.cod_div
	 join orgao o on d.cod_div=o.cod_orgao

select f.matricula,f.nome_func,f.anos_servico       --questao 10
from funcionario f join gerencia g on f.matricula=g.mat_ger
	 join departamento d on g.cod_orgao=d.cod_depto
where (f.salario>2000 or f.matricula>30) and f.anos_servico>6;

select distinct p.* --questao 11
from projeto p join proj_tec t on p.cod_proj=t.cod_proj

select f.nome_func
from funcionario f join gerencia g on f.maticula=g.mat_ger
	join divisao d on g.cod_orgao=d.cod_div             --questao 12
where f.nome_func like '_ND%' or f.nome like '_LA%';

select f.matricula,f.nome_func,fc.cargo,f.anos_servico,f.salario    --questao 13
from funcionario f join func_comum fc on f.matricula=fc.mat_func
where f.anos_servico>=4 or f.salario>500;

select  o.nome_orgao, f.matricula,f.nome_func.f.salario  
from orgao o join departamento d on o.cod_orgao=d.cod_depto
	join funcionario f on f.cod_orgao=o._cod_orgao      --questao 14
	join gerencia g on g_mat_ger=f.matricula
order by o.nome_orgao,f.salario desc;

select 
from funcionario fs join supervisiona s on fs.matricula=s.mat_superior
	join funcionario f on s.mat_func=f.matricula--questao 15
order by fs.matricula,f.matricula;



select f.nome_func,nome_orgao,fs.nome_func
from FUNCIONARIO f
join ORGAO
on f.cod_orgao = ORGAO.cod_orgao   --questao 16
join SUPERVISIONA
on mat_func = f.matricula
join FUNCIONARIO fs
on mat_superior = fs.matricula
join DEPARTAMENTO on ORGAO.cod_orgao = DEPARTAMENTO.cod_depto
order by f.matricula

select cod_div,o1.nome_orgao,cod_depto,o2.nome_orgao
from DIVISAO
join ORGAO o1
on DIVISAO.cod_div = o1.cod_orgao
join SUBORDINADO 
on DIVISAO.cod_div =  SUBORDINADO.cod_div   --questao 17
join DEPARTAMENTO 
on SUBORDINADO.cod_depto = DEPARTAMENTO.cod_depto
join ORGAO o2
on DEPARTAMENTO.cod_depto = o2.cod_orgao

select nome_func, matricula
from FUNCIONARIO                --questao 18
where matricula not in (select mat_ger from GERENCIA)

--19 *****Ñ SEI SE ESTÁ CERTO***** --
select nome_func, matricula, nome_orgao
from FUNCIONARIO
join GERENCIA
on matricula = mat_ger
join DEPARTAMENTO
on cod_depto = FUNCIONARIO.cod_orgao
join ORGAO
on cod_depto = ORGAO.cod_orgao
-- *****Ñ SEI SE ESTÁ CERTO***** --

--19
select nome_func, matricula, nome_orgao
from FUNCIONARIO
join ORGAO
on FUNCIONARIO.cod_orgao = ORGAO.cod_orgao
join DEPARTAMENTO
on ORGAO.cod_orgao = cod_depto
where exists (select mat_ger from GERENCIA
	      where GERENCIA.cod_orgao = cod_depto)

--questao 24
select fs.nome_func,count(s.mat_func)
from funcionario fs join supervisiona s on fs.matricula=s.mat_superior
group fs.nome_func

--questao 25
select d.localizacao,fc.cargo,avg(f.salario)
from departamento d join funcionario f on d.cod_depto=f.cod_orgao
join func_comum fc on f.mat_func=f.matricula
group by d.localizacao,fc.cargo 
having count(*)>1  -->conta os grupos selecionados pela cláusula group by... 

--questao 26
select f.nome_func,p.nome_proj
from funcionario f join aloca a on f.matricula=a.mat_func

--questao 27(esta vai cair na prova!)

select nome_orgao,avg(f.salario) 
from orgao o join departamento d on d.cod_depto=o.cod_orgao
join funcionario f on o.cod_orgao=f.cod_orgao
group by nome_orgao
having avg(f.salario)>(select avg(salario) from funcionario)

façam as devidas adaptações com relação aos nomes ...

	  













