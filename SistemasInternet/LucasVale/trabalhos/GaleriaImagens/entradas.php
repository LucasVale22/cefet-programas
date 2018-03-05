<h1 align="center">Seja Bem-Vindo ao nosso criador de galerias!</h1>
<h3 align="center">Adicione imagens que estejam em uma pasta do seu computador. Se quiser, não precisa adicionar todas:</h3>
</br>
<?php
$qtde=(int)$_REQUEST["qtde"];
if($qtde>10){
	echo "<script>alert('Nossa galeria só permite adicionar até 10 imagens!')</script>";
	echo "<a href='Homepage.php'>Voltar à página inicial</a>";
}
else{
	if($qtde==""){
		echo "<script>alert('Digite uma quantidade, por favor!')</script>";
		echo "<a href='Homepage.php'>Voltar à página inicial</a>";
	}
	else{
		echo "<form action='corte_imagem.php' method='post' enctype='multipart/form-data'>";
		for($j=1;$j<=$qtde;$j++){
			echo "
				<input type='file' name='img$j'/>
				<br/>";
		}
		echo "<input type='submit' value='Expor!'/>
			</form>";
	}
}
?>
