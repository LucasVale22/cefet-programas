
<link rel="stylesheet" type="text/css" href="estilo.css"/>

<div align="center">
<form action="ValidaProjeto.php" method="post">
  <fieldset>
	  </br><legend>Cadastro de projetos</legend>
	  <label for="titproj">Título do Projeto:</label>
	  <input type="text" name="titproj" id="titproj"/><br />
	  <label for="dinicio">Descrição:</label>
	  <textarea name="descricao"></textarea></br>
	  <label for="dinicio">Data de Início:</label>
	  <input type="text" name="dinicio" id="dinicio"/><br />
	  <label for="dtermino">Data de Término:</label>
	  <input type="text" name="dtermino" id="dtermino"/><br />
	  <label for="email">Email do Responsável:</label>
	  <input type="text" name="email" id="email"/><br />
	  <input type="submit" value="Enviar"/>
  </fieldset>
</form>
</div>