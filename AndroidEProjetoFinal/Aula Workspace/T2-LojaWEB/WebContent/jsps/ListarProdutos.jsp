<%@include file="_header.jsp"%>

<%@page language="java" contentType="text/html; charset=ISO-8859-1" pageEncoding="ISO-8859-1"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>

<title>Listagem de Produtos</title>

<table width="80%" border="1">
	<caption>LISTAGEM DE PRODUTOS</caption>
	<tr>
		<th>Código</th>
		<th>Descrição</th>
		<th>Categoria</th>
		<th align="right">Valor (R$)</th>
	</tr>

	<!-- Variável para calcular o preço total dos produtos -->
	<c:set var="total" value="0" scope="page" />
	<c:forEach items="${requestScope.produtos}" var="produto" >
		<tr>
			<td>
				<a href="/LojaWEB/lojaweb?cmd=realizarConsultaProduto&idProduto=${produto.id}">
					<c:out value="${produto.codigo}" />
				</a>
			</td>
			<td><c:out value="${produto.nome}" /></td>
			<td><c:out value="${produto.nomeCategoria}" /></td>
			<td align="right">
				<fmt:formatNumber type="number" maxIntegerDigits="5" maxFractionDigits="2" minFractionDigits="2" value="${produto.valor}" />
			</td>

			<!-- Incremento da variável totalizadora com o valor do item corrente -->
			<c:set var="total" value="${total + produto.valor}" />
		</tr>
	</c:forEach>
	<tr>
		<td colspan="4" align="right">
			<b>
				Total em produtos:
				<fmt:formatNumber type="currency" value="${total}" />
			</b> 
		</td>
	</tr>
</table>

<%@include file="_footer.jsp" %>
