package br.cefetrj.lojaweb.ui;

public class Usuario {

	public static int qtdUsuarios = 0;

	String login;
	String nome;
	String senha;	

	public Usuario(String login, String nome, String senha) {
		super();
		this.login = login;
		this.nome = nome;
		this.senha = senha;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getLogin() {
		return login;
	}

	public void setLogin(String login) {
		this.login = login;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}
	
}
