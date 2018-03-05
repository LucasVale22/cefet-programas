create table orgao
(
	cod_orgao integer not null,
	nome_orgao varchar(50),
	constraint pkOrgao primary key(cod_orgao)
);

create table funcionario
(
	matricula integer not null,
	nome_func varchar(50),
	anos_servico date,
	salario float,
	cod_orgao integer,
	constraint pkFunc primary key(matricula),
	constraint ck1 check(salario>0),
	constraint fk1 foreign key(cod_orgao) references orgao(cod_orgao) 
);

create table departamento
(
	cod_depto integer not null,
	localizacao varchar(50),
	constraint pkDepto primary key(cod_depto),
	constraint fk2 foreign key(cod_depto) references orgao(cod_orgao)
);

create table divisao
(
	cod_div integer not null,
	constraint pkDiv primary key(cod_div),
	constraint fk3 foreign key(cod_div) references orgao(cod_orgao)
);

create table subordinado
(
	cod_depto integer not null,
	cod_div integer not null,
	constraint pkSub primary key(cod_depto,cod_div),
	constraint fk4 foreign key(cod_depto) references departamento(cod_depto),
	constraint fk5 foreign key(cod_div) references divisao(cod_div)
);

create table gerencia
(
	mat_ger integer not null,
	cod_orgao integer not null,
	constraint pkGerencia primary key(mat_ger,cod_orgao),
	constraint fk6 foreign key(mat_ger) references funcionario(matricula),
	constraint fk7 foreign key(cod_orgao) references orgao(cod_orgao)
);

create table func_comum
(
	mat_func integer not null,
	cargo varchar(50),
	constraint pkFc primary key(mat_func),
	constraint fk8 foreign key(mat_func) references funcionario(matricula)
);

create table projeto
(
	cod_proj integer not null,
	nome_proj varchar (50),
	inicio date,
	fim date,
	constraint pkProj primary key(cod_proj)
);

create table aloca
(
	cod_proj integer not null,
	mat_func integer not null,
	data_alocacao date,
	constraint pkAl primary key(cod_proj,mat_func),
	constraint fk10 foreign key(cod_proj) references projeto(cod_proj),
	constraint fk11 foreign key(mat_func) references funcionario(matricula)
);

create table coordena
(
	cod_proj integer not null,
	mat_coord integer not null,
	data_alocacao date,
	constraint pkCoord primary key(cod_proj,mat_coord),
	constraint fk12 foreign key(cod_proj) references projeto(cod_proj),
	constraint fk13 foreign key(mat_coord) references funcionario(matricula)
);

create table supervisiona
(
	mat_superior integer not null,
	mat_func integer not null,
	constraint pkSuperv primary key(mat_superior,mat_func),
	constraint fk14 foreign key(mat_superior) references funcionario(matricula),
	constraint fk15 foreign key(mat_func) references funcionario(matricula)
);

create table proj_tecnico
(
	cod_proj integer not null,
	area_pesquisa varchar(50),
	constraint pkPt primary key(cod_proj),
	constraint fk16 foreign key(cod_proj) references projeto(cod_proj) 
);




