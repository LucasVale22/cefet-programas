package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.sql.DataSource;

public class SalvarInclusaoUsuarioComando implements IComando {

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		DataSource ds = null;
		Connection c = null;
		PreparedStatement stmt = null;
		String pagina;
		try {
			Context initCtx = new InitialContext();
			ds = (DataSource) initCtx.lookup("java:comp/env/jdbc/TesteBD");
			c = ds.getConnection();

			String sql = "insert into Usuario(nome, login, senha) values(?,?,?)";
			stmt = c.prepareStatement(sql);

			stmt.setString(1, request.getParameter("nome"));
			stmt.setString(2, request.getParameter("login"));
			stmt.setString(3, request.getParameter("senha"));

			int resultado = stmt.executeUpdate();
			if (resultado == 1) {
				List<Usuario> usrs = obterUsuarios();
				request.setAttribute("usuarios", usrs);
				pagina = "/jsps/ListarUsuarios.jsp";
			} else {
				String msg = "Houve um erro na inserção de dados!";
				pagina = "/jsps/Erro.jsp";
			}
		} catch (Exception e) {
			String msg = "ERROR! " + e.getMessage();
			pagina = "/jsps/Erro.jsp";
		} finally {
			try {
				if (stmt != null) {
					stmt.close();
				}
				if (c != null) {
					c.close();
				}
			} catch (Exception e2) {
				String msg = "Unable to close connection: " + e2.getMessage();
				pagina = "/jsps/Erro.jsp";
			}
		}
		return pagina;
	}

	private List<Usuario> obterUsuarios() throws NamingException, SQLException {
		List<Usuario> usuarios = new ArrayList<Usuario>();
		DataSource ds = null;
		Connection c = null;
		Statement Stmt = null;
		ResultSet RS = null;
		try {
			Context initCtx = new InitialContext();
			ds = (DataSource) initCtx.lookup("java:comp/env/jdbc/TesteBD");
			c = ds.getConnection();

			Stmt = c.createStatement();
			String sql = "select senha, nome, login from Usuario";
			ResultSet rs = Stmt.executeQuery(sql);
			while (rs.next()) {
				String login = rs.getString("login");
				String nome = rs.getString("nome");
				String senha = rs.getString("senha");
				Usuario u = new Usuario(login, nome, senha);
				usuarios.add(u);
			}

		} finally {
			if (RS != null) {
				RS.close();
			}
			if (Stmt != null) {
				Stmt.close();
			}
			if (c != null) {
				c.close();
			}
		}
		return usuarios;
	}
}
