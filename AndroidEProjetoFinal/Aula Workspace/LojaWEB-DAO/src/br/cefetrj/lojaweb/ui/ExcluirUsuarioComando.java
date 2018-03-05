package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ExcluirUsuarioComando implements IComando {

	String login = null;
	@Override
	public String executar(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException
	{
		String pagina;
		String login = getLogin();

		try {
			Connection c = GerenteBD.obterConexao();
			String sql = "delete from usuario where login=?";
			PreparedStatement pst = c.prepareStatement(sql);
			pst.setString(1, login);
			int rs = pst.executeUpdate();
			
			if (rs == 1)
			{
				pagina = "/jsps/ListarUsuarios.jsp";
			}
			else
			{
				pagina = "/jsps/Erro.jsp";
			}

			pagina = "/jsps/ExcluirUsuario.jsp";

		} catch (NamingException | SQLException e) {
			request.setAttribute("msgErro", "Listagem não pode ser obtida.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}

		return pagina;
	}
	public ExcluirUsuarioComando(String login)
	{
		this.login=login;
	}
	private String getLogin()
	{
		return this.login;
	}
}
