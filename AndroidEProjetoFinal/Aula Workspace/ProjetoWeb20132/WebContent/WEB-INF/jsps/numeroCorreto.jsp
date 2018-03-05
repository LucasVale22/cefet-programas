<html>
<head>
<link rel="stylesheet" href="include/estilo.css" />
<title>Exemplo de página JSP</title>
</head>
<body>
	<h1>Teste JSP</h1>

	<ul>
		<%
			int i = 234;

			for (int j = 0; j < 10; j++) {
				i = i + 20;
				out.println("<li>" + i + "</li>");
			}
		%>
	</ul>

</body>
</html>
