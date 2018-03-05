create table Usuario(
	login char(10) not null primary key,
	nome char(40) not null,
	senha char(10) not null
);

insert into Usuario(login, nome, senha) values('admin', 'Administrador', 'admin');
insert into Usuario(login, nome, senha) values('careca', 'Leandro Chernicharo', 1234);
insert into Usuario(login, nome, senha) values('temp', 'Temporário', 'teste'); 

create sequence id_produto;
create sequence id_categoria_produto;

create table Produto(
	id				int		default nextval('id_produto') not null primary key,
	codigo			char(6)		unique not null,
	nome			char(40) 	not null,
	valor			decimal(10,2),
	idCategoria		int	not null
);

create table CategoriaProduto(
	id		int		default nextval('id_categoria_produto') not null primary key,
	nome	char(25) 	not null
);

insert into CategoriaProduto(nome) values('Foto & Vídeo');
insert into CategoriaProduto(nome) values('Celulares');
insert into CategoriaProduto(nome) values('Games');
insert into CategoriaProduto(nome) values('Cama & Mesa');

alter table Produto add constraint FK_Produto_Categoria foreign key(idCategoria) references CategoriaProduto(id);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD3161', 'Câmera Digital CS234', 359, 1);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD3565', 'Capa de Silicone Para Celular', 13.5, 2);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD0101', 'Carregador de Celular Nokia', 30.5, 2);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD1560', 'Filmadora HD', 3000, 1);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD4352', 'Guitarra para PS3 (Guitar Hero)', 274, 3);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD2121', 'Controle Sem Fio Para PlayStation 3', 199.99, 3);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD1238', 'Cartão de Memória SD 2GB', 49.99, 1);

insert into Produto(codigo, nome, valor, idCategoria)
values('PD2338', 'Videogame XBox 360 60 GB', 1499.90, 3);
