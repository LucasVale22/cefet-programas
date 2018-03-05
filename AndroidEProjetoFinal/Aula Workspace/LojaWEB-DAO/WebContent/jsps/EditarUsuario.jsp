<?xml version="1.0" encoding="ISO-8859-1" ?>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<title>Inclusão de usuário</title>
</head>
<body>
	<%
		String login = request.getParameter("login");
		String nome = request.getParameter("nome");
		String senha = request.getParameter("senha");
	%>
	<form action="/LojaWEB/lojaweb" method="post">
		<div>Nome:</div>
		<div>
			<input type="text" name="nome" size="30" maxlength="40" value=<%=nome%> />
		</div>
		<div>Login:</div>
		<div>
			<input type="text" name="login" size="8" maxlength="10" value=<%=login%> />
		</div>
		<div>Senha:</div>
		<div>
			<input type="text" name="senha" size="8" maxlength="10" value=<%=senha%> />
		</div>
		<br />
		<div>
			<input type="submit" name="salvar" value="Salvar" />
		</div>

		<input type="hidden" name="cmd" value="salvarEdicaoUsuario" />
		<input type="hidden" name="loginAntigo" value=<%=login%> />
	</form>
	<br />
	<%@include file="_footer.jsp"%>