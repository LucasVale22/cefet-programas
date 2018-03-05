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

import br.cefetrj.lojaweb.dao.ProdutoDao;

public class SalvarInclusaoProdutoComando implements IComando {

	ProdutoDao produtoDao = new ProdutoDao();
	Produto produto;
	
	public SalvarInclusaoProdutoComando(Produto produto)
	{
		this.produto = produto;
	}

	@Override
	public String executar(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException, NamingException, SQLException
	{
		String pagina;
		Produto p = getProduto();
		int rs=produtoDao.inserir(p);
		if(rs == 1)
		{
			List<Produto> usrs = produtoDao.obterProdutos();
			request.setAttribute("produtos", usrs);
			pagina = "/jsps/ListarProdutos.jsp";
		}
		else
		{
			String msg = "Houve um erro na inserção de dados!";
			pagina = "/jsps/Erro.jsp";
		}
		return pagina;
	}

	private Produto getProduto()
	{
		return this.produto;
	}
}