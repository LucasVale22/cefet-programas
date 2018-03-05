<HTML>

<HEAD>
<TITLE>Listagem de Usuário</TITLE>
</HEAD>

<BODY>
<center>
<A HREF="Index.html">Menu Principal</A><BR>
</center>
<%@ page language="java" import="java.sql.*,javax.naming.*,javax.sql.*"%>
<%
	DataSource ds = null;
	Connection c = null;
	Statement Stmt = null;
	ResultSet RS = null;
	try {
		Context initCtx = new InitialContext();
		ds = (DataSource) initCtx
				.lookup("java:comp/env/jdbc/TesteBD");
		c = ds.getConnection();

		Stmt = c.createStatement();
		String sql = "select id, nome, login from Usuarios";
		ResultSet rs = Stmt.executeQuery(sql);
		while (rs.next()) {
			int id = rs.getInt("id");
			String login = rs.getString("login");
			out.println("<p>" + id + "\t" + login + "</p>");
		}

	} catch (Exception e) {
		out.println("ERROR! " + e.getMessage());
	} finally {
		try {
			if (RS != null) {
				RS.close();
			}
			if (Stmt != null) {
				Stmt.close();
			}
			if (c != null) {
				c.close();
			}
		} catch (Exception e2) {
			out.println("Unable to close connection: "
					+ e2.getMessage());
		}
	}
%>
</BODY>
</HTML>