package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.sql.DataSource;

public class EfetuarLoginComando implements IComando {

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		String pagina;

		String senha = request.getParameter("password");
		String login = request.getParameter("login");

		boolean ehUsuarioValido;

		try {
			ehUsuarioValido = autenticarUSuario(login, senha);
		} catch (NamingException | SQLException e) {
			ehUsuarioValido = false;
			e.printStackTrace();
		}

		if (ehUsuarioValido) {
			pagina = "/jsps/menu.jsp";
			HttpSession sessao = request.getSession();
			sessao.setAttribute("usuario", login);
		} else {
			request.setAttribute("mensagem", "Login ou senha inválidos.");
			pagina = "/jsps/Erro.jsp";
		}

		return pagina;
	}

	private boolean autenticarUSuario(String login, String senha)
			throws NamingException, SQLException {
		DataSource ds = null;
		Connection c = null;
		PreparedStatement stmt = null;
		ResultSet rs = null;
		try {
			c = GerenteBD.obterConexao();

			String sql = "select * from Usuario where login = ? and senha = ?";
			stmt = c.prepareStatement(sql);
			stmt.setString(1, login);
			stmt.setString(2, senha);
			rs = stmt.executeQuery();
			return rs.next();
		} finally {
			if (rs != null) {
				rs.close();
			}
			if (stmt != null) {
				stmt.close();
			}
			if (c != null) {
				c.close();
			}
		}
	}

}
