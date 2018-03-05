<?php
	$a=150;
	$b=150;
	$d="uploads";
	if(is_dir($d)){
		if ($dh = opendir($d)) {
			while($f=readdir($dh)){
					if(preg_match('/min-(?P<name>[^.]+).jpg/',$f,$m))
					{
						unlink("uploads/$f");
					}
						
			}
			
		}
		closedir($dh);
	}
	for($i=1;$i<=10;$i++){
		$x=$_FILES["img$i"]["tmp_name"];
		$name=$_FILES["img$i"]["name"];
		if ($name!=""){
			$origem=imagecreatefromjpeg($x);
			list($w,$h)=getimagesize($x);
			$dest=imagecreatetruecolor($a,$b);
			if($w>$h){
				$x0=($w-0.8*$h)/2;
				$y0=0.1*$h;
				imagecopyresized($dest,$origem,0,0,$x0,$y0,$a,$b,0.8*$h,0.8*$h); //os primeiros quatro parâmetros representam as posições x e y, do corte retangular do destino e da origem, respectivamente. Os segundos quatros parâmetros representam as dimensões do corte retangular destino e da origem, respectivamente. 
			}
			else{
				$x0=0.1*$w;
				$y0=($h-0.8*$w)/2;
				imagecopyresized($dest,$origem,0,0,$x0,$y0,$a,$b,0.8*$w,0.8*$w);
			}
			imagejpeg($dest,"uploads/min-$name");
			move_uploaded_file($x,"uploads/$name");
			imagedestroy($origem);
			imagedestroy($dest);
			header("location: galeria2.php");
		
		}
	}
?>

