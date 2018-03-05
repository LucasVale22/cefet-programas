<h1>Teste</h1>
<ul>
<?php 
	$a=array();
	$a[0]=0;
	$a[1]=2;
	$a[500]=1000;
	$a["lucas"]=2000;
	echo count($a);
	foreach($a as $x)
	{
		echo"<p>$x</p>";
	}
?>
</ul>
