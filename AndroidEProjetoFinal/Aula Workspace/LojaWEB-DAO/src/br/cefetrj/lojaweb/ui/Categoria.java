package br.cefetrj.lojaweb.ui;

public class Categoria {

	private String nome;
	private int id;

	public Categoria(int id, String nome) {
		this.id = id;
		this.nome=nome;
	}

	public int getId() {
		return id;
	}
	
	public String getNome() {
		return nome;
	}
}
