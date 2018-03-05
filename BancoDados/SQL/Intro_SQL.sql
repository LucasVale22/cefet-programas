create table cidade
(
	codigo integer not null, 
	nome varchar(50),
	UF char(2),
	constraint pkCidade primary key(codigo),
	constraint ck1 check (nome is not null),
	constraint ck2 check (UF is not null),
	constraint ck3 check(UF='RJ' or UF='SP' or UF='MG' or UF='ES')
);

create table clientes
(
	matricula serial primary key,
	nome varchar(30) not null,
	endereco varchar(50) not null,
	cidade integer,
	constraint fk1 foreign key (cidade) references cidade(codigo)
);

alter table cidade
add column qtde_habitantes integer default 0;