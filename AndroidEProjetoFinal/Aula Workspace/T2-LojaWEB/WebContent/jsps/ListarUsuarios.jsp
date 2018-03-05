<%@include file="_header.jsp"%>

<%@page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>

<title>Listagem de Usuários</title>

<table width="80%" border="1">
	<caption>Listagem de Usuários</caption>
	<tr>
		<th>Nome</th>
		<th>Login</th>
		<th>Senha</th>
	</tr>

	<c:forEach items="${requestScope.usuarios}" var="usr">
		<tr>
			<td><c:out value="${usr.nome}" /></td>
			<td><c:out value="${usr.login}" /></td>
			<td><c:out value="${usr.senha}" /></td>
		</tr>
	</c:forEach>
</table>

<%@include file="_footer.jsp"%>
