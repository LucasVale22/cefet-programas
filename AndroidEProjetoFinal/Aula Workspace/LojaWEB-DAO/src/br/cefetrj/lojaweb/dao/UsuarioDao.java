package br.cefetrj.lojaweb.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.naming.NamingException;

import br.cefetrj.lojaweb.ui.GerenteBD;
import br.cefetrj.lojaweb.ui.Usuario;

public class UsuarioDao {
	
	public int inserir(Usuario usuario) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "INSERT INTO usuario(login, nome, senha) VALUES(?, ?, ?)";
		PreparedStatement pst = c.prepareStatement(sql);
		
		pst.setString(1, usuario.getLogin());
		pst.setString(2, usuario.getNome());
		pst.setString(3, usuario.getSenha());
		
		return pst.executeUpdate();
	}
	
	public void excluir(String login) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "DELETE from usuario WHERE login=?";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setString(1, login);
		pst.executeUpdate();
	}
	
	public int atualizar(Usuario usuario, String login) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "UPDATE usuario SET login=?, nome=?, senha=? WHERE login=?";
		PreparedStatement pst = c.prepareStatement(sql);
		
		pst.setString(1, usuario.getLogin());
		pst.setString(2, usuario.getNome());
		pst.setString(3, usuario.getSenha());
		pst.setString(4, login);
		
		return pst.executeUpdate();
	}
	
	public List<Usuario> obterUsuarios() throws SQLException, NamingException {
		Connection c = GerenteBD.obterConexao();
		String sql = "SELECT login, nome, senha FROM usuario";
		PreparedStatement pst = c.prepareStatement(sql);
		ResultSet rs = pst.executeQuery();
		List<Usuario> usuarios = new ArrayList<Usuario>();
		while (rs.next()) {

			String login = rs.getString("login");
			String nome = rs.getString("nome");
			String senha = rs.getString("senha");

			Usuario u = new Usuario(login, nome, senha);
			usuarios.add(u);
		}
		return usuarios;
	}
}
