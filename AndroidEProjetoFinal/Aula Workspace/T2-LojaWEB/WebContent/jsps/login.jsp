<!-- Importa a taglib CORE com o prefixo "c" -->
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<html>

<head>
<link rel="stylesheet" href="include/estilo.css" />
<title>Loja WEB</title>
</head>

<body>

<h1>Loja WEB</h1>

<p><img src="include/index/LojaVirtual.jpg" width="140" height="140" />
</p>

<form action="/LojaWEB/lojaweb" method="post"><input
	type="hidden" name="cmd" value="login">

<table>
	<tr>
		<td>Login:</td>
		<td><input type="text" name="login" size="20" /></td>
	</tr>

	<tr>
		<td>Senha:</td>
		<td><input type="password" name="password" size="20" /></td>
		<td><input type="submit" name="btnConfirma" value="Entrar" /></td>
	</tr>
</table>
</form>

<c:if test="${param.mensagem != null}">
	<font color=white> <c:out value="${param.mensagem}" /> </font>
</c:if>

</body>
</html>