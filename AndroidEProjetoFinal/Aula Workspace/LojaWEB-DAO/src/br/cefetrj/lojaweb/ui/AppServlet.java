package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class AppServlet
 */
@WebServlet("/AppServlet")
public class AppServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public AppServlet() {
		super();
	}

	protected void processaRequisicao(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		String strComando = request.getParameter("cmd");

		IComando cmd = null;

		if (strComando.equals("login")) {
			cmd = new EfetuarLoginComando();
		} else if (strComando.equals("listarProdutos")) {
			cmd = new ListarProdutosComando();
		} else if (strComando.equals("incluirProduto")) {
			cmd = new ApresentarFormInclusaoProdutoComando();
		} else if (strComando.equals("incluirUsuario")) {
			cmd = new ApresentarFormInclusaoUsuarioComando();
		} else if (strComando.equals("salvarInclusaoUsuario")) {
			cmd = new SalvarInclusaoUsuarioComando();
		} else if (strComando.equals("excluirUsuario")) {
			cmd = new ApresentarFormExclusaoUsuarioComando();
		} else if (strComando.equals("salvarExclusaoUsuario")) {
			cmd = new SalvarExclusaoUsuarioComando();
		} else if (strComando.equals("salvarAlteracaoUsuario")) {
			cmd = new SalvarAlteracaoUsuarioComando();
		} else if (strComando.equals("alterarUsuario")) {
			cmd = new ApresentarFormAlteracaoUsuarioComando();
		}
		

		if (cmd != null) {
			String pagina = cmd.executar(request, response);
			getServletContext().getRequestDispatcher(pagina).forward(request,
					response);
		} else {
			response.sendRedirect("/LojaWEB/jsps/notFound.jsp");
		}
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doGet(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		processaRequisicao(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse
	 *      response)
	 */
	protected void doPost(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		processaRequisicao(request, response);
	}

}
