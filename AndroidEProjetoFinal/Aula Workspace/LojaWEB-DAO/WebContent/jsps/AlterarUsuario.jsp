<?xml version="1.0" encoding="ISO-8859-1" ?>
<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />
<title>Exclusão de Usuario</title>
</head>
<body>
Insira o nome do usuário a ser alterado:
	<form action="/LojaWEB/lojaweb" method="post">
		<div>Usuario a ser modificado:</div>
		<div>
			<input type="text" name="nomeantigo" size="30" maxlength="40" />
		</div>
		<div>Novo Nome:</div>
		<div>
			<input type="text" name="nome" size="30" maxlength="40" />
		</div>
		<div>Novo Login:</div>
		<div>
			<input type="text" name="login" size="30" maxlength="40" />
		</div>
		<div>Nova Senha:</div>
		<div>
			<input type="text" name="senha" size="30" maxlength="40" />
		</div>
		<div>
			<input type="submit" name="salvar" value=" Salvar " />
		</div>

		<input type="hidden" name="cmd" value="salvarAlteracaoUsuario" />
	</form>
	<br />
	<%@include file="_footer.jsp"%>