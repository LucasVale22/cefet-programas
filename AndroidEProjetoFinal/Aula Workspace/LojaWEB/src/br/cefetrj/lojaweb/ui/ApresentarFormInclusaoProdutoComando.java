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

public class ApresentarFormInclusaoProdutoComando implements IComando {

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		String pagina = null;
		try {
			Connection c = GerenteBD.obterConexao();

			String sql = "select id, nome from CategoriaProduto";

			PreparedStatement pst = c.prepareCall(sql);
			ResultSet rs = pst.executeQuery();

			List<Categoria> categorias = mapearCategorias(rs);

			request.setAttribute("categorias", categorias);

			pagina = "/jsps/IncluirProduto.jsp";

		} catch (NamingException | SQLException e) {
			request.setAttribute("msgErro",
					"Erro na apresentação do form. de inclusão de produtos.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}
		return pagina;
	}

	private List<Categoria> mapearCategorias(ResultSet rs) throws SQLException {
		List<Categoria> categorias = new ArrayList<Categoria>();
		while (rs.next()) {

			int id = rs.getInt("id");
			String nome = rs.getString("nome");
			Categoria c = new Categoria(id, nome);
			categorias.add(c);
		}
		return categorias;
	}

}
