<HTML>

<HEAD>
<TITLE>Alteração de Usuários</TITLE>
</HEAD>

<BODY>
	<center>
		<A HREF="Index.html">Menu Principal</A><BR>
	</center>
	<%@ page language="java" import="java.sql.*,javax.naming.*,javax.sql.*"%>
	<%
		DataSource ds = null;
		Connection c = null;
		PreparedStatement stmt = null;
		try {
			Context initCtx = new InitialContext();
			ds = (DataSource) initCtx.lookup("java:comp/env/jdbc/TesteBD");
			c = ds.getConnection();
			
			int id = Integer.valueOf(request.getParameter("id"));

			String sql = "update usuarios set nome=?, login=?, senha=? where id=?";
			stmt = c.prepareStatement(sql);

			stmt.setString(1, request.getParameter("nome"));
			stmt.setString(2, request.getParameter("login"));
			stmt.setString(3, request.getParameter("senha"));
			stmt.setInt(4,id);

			int resultado = stmt.executeUpdate();
			if (resultado == 1) {
				out.println("Usuário alterado com sucesso!");
			} else {
				out.println("Houve um erro na alteração de dados!");
			}
		} catch (Exception e) {
			out.println("ERROR! " + e.getMessage());
		} finally {
			try {
				if (stmt != null) {
					stmt.close();
				}
				if (c != null) {
					c.close();
				}
			} catch (Exception e2) {
				out.println("Unable to close connection: "
						+ e2.getMessage());
			}
		}
		response.sendRedirect("listarUsuarios.jsp");
	%>
</BODY>
</HTML>