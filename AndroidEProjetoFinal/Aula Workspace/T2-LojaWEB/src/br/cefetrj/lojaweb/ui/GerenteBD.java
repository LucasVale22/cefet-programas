package br.cefetrj.lojaweb.ui;

import java.sql.Connection;
import java.sql.SQLException;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;

public class GerenteBD {
	public static Connection obterConexao() throws NamingException, SQLException {
		DataSource ds;
		Connection c;
		Context initCtx = new InitialContext();
		ds = (DataSource) initCtx.lookup("java:comp/env/jdbc/TesteBD");
		c = ds.getConnection();
		return c;
	}
}
