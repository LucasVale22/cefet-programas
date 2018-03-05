package br.cefetrj.lojaweb.ui;

public class Produto {
	int id;
	String codigo;
	String nome;
	double valor;
	Categoria categoria;

	public Produto(int id, String codigo, String nome, double valor,
			Categoria categoria) {
		super();
		this.id = id;
		this.codigo = codigo;
		this.nome = nome;
		this.valor = valor;
		this.categoria = categoria;
	}

	public int getId() {
		return id;
	}

	public String getCodigo() {
		return codigo;
	}

	public String getNome() {
		return nome;
	}

	public double getValor() {
		return valor;
	}

	public Categoria getCategoria() {
		return this.categoria;
	}
}
