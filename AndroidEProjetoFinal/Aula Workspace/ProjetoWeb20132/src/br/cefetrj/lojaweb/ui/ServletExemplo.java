package br.cefetrj.lojaweb.ui;


import java.io.IOException;
import java.util.Random;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class ServletExemplo
 */
@WebServlet("/ServletExemplo")
public class ServletExemplo extends HttpServlet {
	private static final long serialVersionUID = 1L;

	protected void processaRequisicao(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		String strComando = request.getParameter("cmd");

		if (strComando.equals("adivinhar")) {
			Random r = new Random();
			String entrada = request.getParameter("numero");
			Integer numeroFornecido = Integer.parseInt(entrada);
			Integer valorGerado = r.nextInt(3);

			if (valorGerado == numeroFornecido) {
				String pagina = "/ProjetoWeb20132/jsps/numeroCorreto.jsp";
				getServletContext().getRequestDispatcher(pagina).forward(request,
						response);
			} else {
				String pagina = "/ProjetoWeb20132/jsps/numeroErrado.jsp";
				getServletContext().getRequestDispatcher(pagina).forward(request,
						response);
			}
		} else {
			response.sendRedirect("/ProjetoWeb20132/jsps/notFound.jsp");
		}
	}	
	
    /**
     * Default constructor. 
     */
    public ServletExemplo() {
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processaRequisicao(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processaRequisicao(request, response);
	}

}
