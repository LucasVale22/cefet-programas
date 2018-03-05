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

import br.cefetrj.lojaweb.dao.UsuarioDao;

public class SalvarEdicaoUsuarioComando implements IComando {

	String login;
	Usuario usuario;
	UsuarioDao usuarioDao = new UsuarioDao();
	
	public SalvarEdicaoUsuarioComando(Usuario usuario, String login)
	{
		this.usuario=usuario;
		this.login=login;
	}
	
	@Override
	public String executar(HttpServletRequest request,HttpServletResponse response) throws ServletException,IOException, SQLException, NamingException
	{
		String pagina;
		Usuario u = getUsuario();
		int rs=usuarioDao.atualizar(u, login);
		if(rs == 1)
		{
			List<Usuario> usrs = usuarioDao.obterUsuarios();
			request.setAttribute("usuarios", usrs);
			pagina = "/jsps/ListarUsuarios.jsp";
		}
		else
		{
			String msg = "Houve um erro na inserção de dados!";
			pagina = "/jsps/Erro.jsp";
		}
		return pagina;
	}
	
	private Usuario getUsuario()
	{
		return this.usuario;
	}
}
