<HTML>

<HEAD>
<TITLE>Listagem de Usuário</TITLE>
</HEAD>

<BODY>
	<center>
		<A HREF="Index.html">Menu Principal</A><BR>
	</center>
	<h3>Usuários</h3><br/>
	<table border=1>
		<tr>
			<th>Nome</th>
			<th>Login</th>
			<th>Senha</th>
			<th>Operação</th>
		</tr>
	<%@ page language="java" import="java.sql.*,javax.naming.*,javax.sql.*"%>
	<%
		DataSource ds = null;
		Connection c = null;
		Statement stmt = null;
		try {
			Context initCtx = new InitialContext();
			ds = (DataSource) initCtx.lookup("java:comp/env/jdbc/TesteBD");
			c = ds.getConnection();
			
			stmt = c.createStatement();
		
		String sql = "select * from Usuarios;";
		ResultSet rs = stmt.executeQuery(sql);	
		
		while (rs.next()) {
			int id = rs.getInt("id");
			String nome = rs.getString("nome");
			String login = rs.getString("login");
			String senha = rs.getString("senha");			
			%><tr>
				<td><%=nome%></td>
				<td><%=login%></td>
				<td><%=senha%></td>
				<td><a href="ExcluirUsuarios.jsp?id=<%=id%>">Excluir</a></td>
				<td><a href="alterarForm.jsp?id=<%=id%>">Alterar</a></td>			
			</tr><%
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
%>
	</table>
	<br/>
	<a href="insereForm.html">Inserir Usuario</a>
</BODY>
</HTML>