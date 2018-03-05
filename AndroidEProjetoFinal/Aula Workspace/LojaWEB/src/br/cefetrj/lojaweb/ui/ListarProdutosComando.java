package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import br.cefetrj.lojaweb.dao.ProdutoDao;

public class ListarProdutosComando implements IComando {

	ProdutoDao produtoDao = new ProdutoDao();

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		String pagina;

		try {
			List<Produto> produtos = produtoDao.obterProdutos();

			request.setAttribute("produtos", produtos);

			pagina = "/jsps/ListarProdutos.jsp";

		} catch (NamingException | SQLException e) {
			request.setAttribute("msgErro", "Listagem não pode ser obtida.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}

		return pagina;
	}

}
