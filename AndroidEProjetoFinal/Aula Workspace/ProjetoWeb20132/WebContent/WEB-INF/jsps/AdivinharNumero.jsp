<%@page import="java.util.Random"%>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
	<%
		Random r = new Random();
		String entrada = request.getParameter("numero");
		Integer numeroFornecido = Integer.parseInt(entrada);
		Integer valorGerado = r.nextInt(3);

		if (valorGerado == numeroFornecido) {
			out.println("Você acertou o número!");
		} else {
			pageContext.forward("AvivinharNumero.html");
// 			out.println("Você errou. Tente novamente.");
		}
	%>
</body>
</html>