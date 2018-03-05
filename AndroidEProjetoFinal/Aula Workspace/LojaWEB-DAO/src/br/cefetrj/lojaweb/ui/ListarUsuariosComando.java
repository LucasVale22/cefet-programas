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

import br.cefetrj.lojaweb.dao.UsuarioDao;

public class ListarUsuariosComando implements IComando {

	UsuarioDao usuarioDao = new UsuarioDao();
	
	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {
		String pagina;

		try
		{
			List<Usuario> usuarios = usuarioDao.obterUsuarios();
			request.setAttribute("usuarios", usuarios);
			pagina = "/jsps/ListarUsuarios.jsp";
		}
		catch (NamingException | SQLException e)
		{
			request.setAttribute("msgErro", "Listagem não pode ser obtida.");
			pagina = "/jsps/Erro.jsp";
			e.printStackTrace();
		}

		return pagina;
	}
}
