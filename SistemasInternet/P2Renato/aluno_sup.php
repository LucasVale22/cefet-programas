<?php
include 'P2.php';
$id=$_REQUEST['id'];
foreach ($CEFET->aluno_sup as $as)
{
	if ($as->id==$id)
	$att=$as;
}
$att->mostra_dados();
echo "</br></br><a href='escola.php'>HOME</a></br></br>";
?>