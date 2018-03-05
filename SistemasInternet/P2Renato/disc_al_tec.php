<?php
include 'P2.php';
$id=$_REQUEST['id'];
$idd=$_REQUEST['idd'];
foreach ($CEFET->aluno_tec as $at)
{
	if ($at->id==$idd)
	$att=$at;
}
foreach($att->disciplinas as $d)
{
	if ($d->id==$id)
	$ad=$d;
}
$ad->mostra_dados();
echo "</br></br><a href='escola.php'>HOME</a></br></br>";
?>