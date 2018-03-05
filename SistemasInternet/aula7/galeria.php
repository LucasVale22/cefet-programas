<h1 align="center">GALERIA</h1>
<?php
	if(is_dir($d)){
		if ($dh = opendir($dir)) {
			if($f=readdir($dh))!==false) {
				while($f=="min-$name.jpg"){
					echo "";								
				}
			}
					closedir($dh);
		}
	}	
?>