package br.cefetrj.lojaweb.ui;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import br.cefetrj.lojaweb.dao.UsuarioDao;

public class ApresentarFormEdicaoUsuarioComando implements IComando {

	String login = null;
	
	private String getLogin()
	{
		return this.login;
	}
	
	public ApresentarFormEdicaoUsuarioComando(String login)
	{
		this.login=login;
	}
	@Override
	public String executar(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException
	{
		String pagina;
		String login = getLogin();
		Usuario u = null;
		UsuarioDao usuarioDao = new UsuarioDao();

		try {
			u = usuarioDao.obterUsuarioEspecifico(login);
			if(u != null)
			{
				pagina = "/jsps/EditarUsuario.jsp?nome="+u.nome+", login="+u.login+", senha="+u.senha+", usuario=<%=u%>";
			}
			else
				pagina = "/jsps/Erro.jsp";

		} catch (NamingException | SQLException e) {
			request.setAttribute("msgErro", "Listagem não pode ser obtida.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}

		return pagina;
	}

}
