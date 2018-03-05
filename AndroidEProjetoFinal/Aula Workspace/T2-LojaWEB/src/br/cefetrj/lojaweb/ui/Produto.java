package br.cefetrj.lojaweb.ui;

public class Produto {
	int id;
	String codigo;
	String nome;
	double valor;
	String nomeCategoria;

	public Produto(int id, String codigo, String nome, double valor,
			String nomeCategoria) {
		super();
		this.id = id;
		this.codigo = codigo;
		this.nome = nome;
		this.valor = valor;
		this.nomeCategoria = nomeCategoria;
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

	public String getNomeCategoria() {
		return nomeCategoria;
	}
}
