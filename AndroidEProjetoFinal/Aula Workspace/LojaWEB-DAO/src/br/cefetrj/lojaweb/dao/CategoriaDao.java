package br.cefetrj.lojaweb.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.naming.NamingException;

import br.cefetrj.lojaweb.ui.Categoria;
import br.cefetrj.lojaweb.ui.GerenteBD;

public class CategoriaDao
{
	public void inserir(Categoria categoria) throws NamingException, SQLException
	{
		Connection c = GerenteBD.obterConexao();
		String sql = "INSERT INTO CategoriaProduto(nome) VALUES(?)";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setString(1, categoria.getNome());
		pst.executeUpdate();
	}
	
	public void excluir(int id) throws NamingException, SQLException
	{
		Connection c = GerenteBD.obterConexao();
		String sql = "DELETE FROM CategoriaProduto WHERE id=?";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setInt(1, id);
		pst.executeUpdate();
	}
	
	public void atualizar(Categoria categoria) throws NamingException, SQLException
	{
		Connection c = GerenteBD.obterConexao();
		String sql = "UPDATE CategoriaProduto SET nome=?";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setString(1, categoria.getNome());
		pst.executeUpdate();
	}
	
	public Categoria obterPorId(int id) throws NamingException, SQLException
	{
		Connection c = GerenteBD.obterConexao();
		String sql = "SELECT nome FROM CategoriaProduto WHERE id=?";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setInt(1, id);
		ResultSet rs = pst.executeQuery();
		
		String nome = rs.getNString("nome");
		
		Categoria categoria = new Categoria(id, nome);
		
		return categoria;
	}
	
	public List<Categoria> mapearCategorias() throws SQLException, NamingException
	{
		Connection c = GerenteBD.obterConexao();
		String sql = "SELECT id, nome FROM CategoriaProduto";
		PreparedStatement pst = c.prepareCall(sql);
		ResultSet rs = pst.executeQuery();
		List<Categoria> categorias = new ArrayList<Categoria>();
		while (rs.next()) {

			int id = rs.getInt("id");
			String nome = rs.getString("nome");
			Categoria cat = new Categoria(id, nome);
			categorias.add(cat);
		}
		return categorias;
	}
}
