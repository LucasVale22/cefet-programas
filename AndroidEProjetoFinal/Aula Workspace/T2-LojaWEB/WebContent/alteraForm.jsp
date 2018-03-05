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
		
			String sql = "select nome,login,senha from Usuarios where id="+id+";";
					
			ResultSet rs = stmt.executeQuery(sql);			
			rs.next();
		
			String nome = rs.getString("nome");
			String login = rs.getString("login");
			String senha = rs.getString("senha");		
%>
	<h2>Modificações</h2>
	<br/>
	<form action="AlterarrUsuarios.jsp" method=post>
		Nome: <input type=text value="<%=nome%>" name="nome"/>
		<br/> 
		Login: <input type=text value="<%=login%>" name="login"/>
		<br/>
		Senha: <input type=text value="<%=senha%>" name="senha"/>
		<br/>
		<input type=hidden value="<%=String.valueOf(id)%>" name="id"/>
		<br/>
		<input type=submit value="OK"/>
		<a href="visualizarUsuarios.jsp">Voltar</a>
	</form>
<%
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
</BODY>
</HTML>