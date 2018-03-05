<h1 align="center">GALERIA</h1>
<?php
	$d="uploads";
	if(is_dir($d)){
		if ($dh = opendir($d)) {
			while($f=readdir($dh)){
					if(preg_match('/min-(?P<name>[^.]+).jpg/',$f,$m))
					{
						echo "<a href='uploads/{$m['name']}.jpg'><img src=\"uploads/$f\" border='0' style='margin:25px;'></a>";
					}
						
			}
			
		}
		closedir($dh);
	}
/*	
	$telefone = "(21)9999-9999";
	
	$er = '/\((?P<ddd>[0-9][0-9])\)(?P<telefone>[0-9]{4}-[0-9]{4})/';
	
	if(preg_match($er,$telefone,$m))
	{
		echo "DDD: {$m['ddd']}";
		echo "TEL: {$m['telefone']}";
		print_r($m);
	}
*/
?>

