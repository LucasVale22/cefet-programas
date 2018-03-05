<?php
include 'P2.php';
$id=$_REQUEST['id'];
foreach ($CEFET->aluno_tec as $at)
{
	if ($at->id==$id)
	$att=$at;
}
$att->mostra_dados();
echo "</br></br><a href='escola.php'>HOME</a></br></br>";
?>