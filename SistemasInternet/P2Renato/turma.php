<?php
include 'P2.php';
$id=$_REQUEST['id'];
foreach ($CEFET->turmas as $t)
{
	if ($t->id==$id)
	$att=$t;
}
$att->mostra_dados();
echo "</br></br><a href='escola.php'>HOME</a></br></br>";
?>