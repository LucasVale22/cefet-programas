package br.cefetrj.lojaweb.ui;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ApresentarFormInclusaoUsuarioComando implements IComando {

	@Override
	public String executar(HttpServletRequest request,
			HttpServletResponse response) throws ServletException, IOException {

		return "/jsps/ExcluirUsuario.jsp";

	}

}