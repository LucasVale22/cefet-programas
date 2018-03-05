<?php
	$a=array(20,10,45,88,75,10,5,20,25,30,40,55);
	$n=count($a);//devolve a qtde de elementos no array...
	$w=800;
	$h=600;
	$im=imagecreatetruecolor($w,$h);
	$fonte="arial.ttf";
	$branco=imagecolorallocate($im,255,255,255);
	$preto=imagecolorallocate($im,0,0,0);
	$cinza=imagecolorallocate($im,168,168,168);
	imagefilledrectangle($im,0,0,800,600,$branco);
	$margem=20;//espaço útil entre o retangulo e o grafico...
	$wr=($w-2*$margem)/$n;//largura de cada raia que comportará um retangulo...
	$hmax=$h-2*$margem;
	$wr80=($wr*8)/10;
	$p1y=$h-$margem;
	$k=100;
	for($i=20;$i<580;$i+=$hmax/10){
		imageline($im,20,$i,780,$i,$cinza);
			imagettftext($im,12,0,0,$i,$preto,$fonte,"$k");
			$k-=10;
		}
	imagettftext($im,12,0,0,$i,$preto,$fonte,"$k");
	for($i=20;$i<780;$i+=($w-2*$margem)/12){
		imageline($im,$i,20,$i,580,$cinza);
		
		}
	for($i=0;$i<$n;$i++){  // ou foreach($a as $i=>$v)...
		$hi=($hmax*$a[$i])/100;
		$xri=$margem+$i*$wr;
		$pi1x=$xri+$wr/10;
		$pi2x=$pi1x+$wr80;
		$pi2y=$p1y-$hi;
		$meio=$xri+$wr/2;
		$num=$i+1;
		$r=rand(0,255);
		$g=rand(0,255);
		$b=rand(0,255);
		$corbarra=imagecolorallocate($im,$r,$g,$b);
		imagefilledrectangle($im,$pi1x,$p1y,$pi2x,$pi2y,$corbarra);
		imagettftext($im,12,0,$meio,$h,$preto,$fonte,"$num");
		}
	imageline($im,20,580,780,580,$preto);
	imageline($im,20,20,20,580,$preto);
	header("content-type:image/png");
	imagepng($im);
	imagecolordeallocate($im,$branco);
	imagedestroy($im);
?>