package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ListarProdutosComando implements IComando {

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		String pagina;

		try {
			Connection c = GerenteBD.obterConexao();
			String sql = "select p.id, p.nome, p.codigo, p.valor, c.nome as nomeCategoria "
					+ "from Produto p join CategoriaProduto c on c.id = p.idCategoria";
			PreparedStatement pst = c.prepareStatement(sql);
			ResultSet rs = pst.executeQuery();

			List<Produto> produtos = mapearProdutos(rs);

			request.setAttribute("produtos", produtos);

			pagina = "/jsps/ListarProdutos.jsp";

		} catch (NamingException | SQLException e) {
			request.setAttribute("msgErro", "Listagem não pode ser obtida.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}

		return pagina;
	}

	private List<Produto> mapearProdutos(ResultSet rs) throws SQLException {
		List<Produto> produtos = new ArrayList<Produto>();
		while (rs.next()) {

			int id = rs.getInt("id");
			String codigo = rs.getString("codigo");
			String nome = rs.getString("nome");
			double valor = rs.getDouble("valor");
			String nomeCategoria = rs.getString("nomeCategoria");

			Produto p = new Produto(id, codigo, nome, valor, nomeCategoria);
			produtos.add(p);
		}
		return produtos;
	}

}
