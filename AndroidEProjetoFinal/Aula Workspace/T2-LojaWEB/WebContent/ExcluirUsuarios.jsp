<HTML>

<HEAD>
<TITLE>Exclusão de Usuário</TITLE>
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
			
			String id = request.getParameter("id");

			String sql = "delete from usuarios where id="+id+";";
			stmt = c.prepareStatement(sql);

			int resultado = stmt.executeUpdate();
			if (resultado == 1) {
				out.println("Usuário excluído com sucesso!");
			} else {
				out.println("Houve um erro na exclusão!");
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