<!-- Importa a taglib CORE com o prefixo "c" -->
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<c:if test="${sessionScope.usuario == null}">
	<jsp:forward page="login.jsp?mensagem=Acesso Restrito" />
</c:if>

<html>

<head> 
	<link rel="stylesheet" href="include/estilo.css" />
	<title>Loja Virtual</title>
</head>

<body>

<div id="container">

	<div id="titulo">
		<p align="left">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a HREF="/LojaVirtual/menu.jsp">Voltar ao menu principal</a>

	<div id="banner">
		
		<p align="right">

			<table>
				<tr>
	
					<td><% out.print("Olá, " + session.getAttribute("usuario") ); %></td>

					<td>
						<form action="/LojaVirtual/Servico" method="post" >
							<input type="hidden" name="cmd" value="logout">
							<input type="submit" name="logout" value="logout">
						</form>
					</td>
	
				</tr>

			</table>

		
	</div>

<!-- </div> -->

<br />