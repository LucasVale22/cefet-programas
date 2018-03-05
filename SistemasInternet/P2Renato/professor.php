<?php
include 'P2.php';
$id=$_REQUEST['id'];
foreach ($CEFET->professores as $p)
{
	if ($p->id==$id)
	$att=$p;
}
$att->mostra_dados();
echo "</br></br><a href='escola.php'>HOME</a></br></br>";
?>