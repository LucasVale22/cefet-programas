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
import br.cefetrj.lojaweb.ui.Produto;

public class ProdutoDao {

	public void incluir(Produto produto) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "insert into produto(codigo, nome, valor, idCategoria) values(?, ?, ?, ?)";
		PreparedStatement pst = c.prepareStatement(sql);

		pst.setString(1, produto.getCodigo());
		pst.setString(2, produto.getNome());
		pst.setDouble(3, produto.getValor());
		pst.setInt(4, produto.getCategoria().getId());

		pst.executeUpdate();

	}

	public void remover(String codigo) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "delete from produto where codigo = ?";
		PreparedStatement pst = c.prepareStatement(sql);
		pst.setString(1, codigo);
		pst.executeUpdate();
	}

	public void atualizar(Produto produto) throws NamingException, SQLException {
		Connection c = GerenteBD.obterConexao();
		String sql = "update produto set codigo = ?, nome = ?, valor = ?, idCategoria = ?";
		PreparedStatement pst = c.prepareStatement(sql);

		pst.setString(1, produto.getCodigo());
		pst.setString(2, produto.getNome());
		pst.setDouble(3, produto.getValor());
		pst.setInt(4, produto.getCategoria().getId());

		pst.executeUpdate();
	}

	public List<Produto> obterProdutos() throws SQLException, NamingException {
		Connection c = GerenteBD.obterConexao();
		String sql = "select p.id, p.nome, p.codigo, p.valor, c.nome as nomeCategoria "
				+ "from Produto p join CategoriaProduto c on c.id = p.idCategoria";
		PreparedStatement pst = c.prepareStatement(sql);
		ResultSet rs = pst.executeQuery();
		List<Produto> produtos = new ArrayList<Produto>();
		while (rs.next()) {

			int id = rs.getInt("id");
			String codigo = rs.getString("codigo");
			String nome = rs.getString("nome");
			double valor = rs.getDouble("valor");

			Integer idCategoria = rs.getInt("idCategoria");

			CategoriaDao categoriaDao = new CategoriaDao();
			Categoria categoria = categoriaDao.obterPorId(idCategoria);

			Produto p = new Produto(id, codigo, nome, valor, categoria);
			produtos.add(p);
		}
		return produtos;
	}
}
