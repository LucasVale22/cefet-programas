<?php
	$a = (float)$_REQUEST["a"];
	$b = (float)$_REQUEST["b"];
	$c = (float)$_REQUEST["c"];
	function f($x){
		global $a, $b, $c;
		$y= $a*$x*$x + $b*$x + $c;			//lembrando que nуo se deve colocar echo antes do header!
		return $y;
	}
	if($a==0){
		echo "O valor de a nуo pode ser zero, senуo serс uma equaчуo do primeiro grau!";
		}
	else{
		$delta=$b*$b-4*$a*$c;
		$x1=(-$b+sqrt($delta))/(2*$a);
		$x2=(-$b-sqrt($delta))/(2*$a);
		$xv=-$b/(2*$a);
		$yv=-$delta/(4*$a);
		$fonte="arial.ttf";
		$w=2048;
		$h=1440;
		$im=imagecreatetruecolor($w,$h);
		$ux=(2.5/100)*$w;      //espaчamento entre as linhas horizontais da grade
		$uy=(2.5/100)*$h;	   //espaчamento entre as linhas verticais da grade
		$variacao=1.0/$ux;
		$fundo=imagecolorallocate($im,255,255,255);
		$preto=imagecolorallocate($im,0,0,0);
		$cinza=imagecolorallocate($im,168,168,168);
		$vermelho=imagecolorallocate($im,255,0,0);
		imagefilledrectangle($im,0,0,$w,$h,$fundo);
		imagefilledellipse($im,$w/2+$x1*$ux,$h/2,7,7,$preto);  
		imagefilledellipse($im,$w/2+$x2*$ux,$h/2,7,7,$preto);
		imagefilledellipse($im,$w/2+$xv*$ux,$h/2,7,7,$preto);		//funчѕes que marcam x1,x2,xv,yv e c com um ponto preto
		imagefilledellipse($im,$w/2,$h/2-$yv*$uy,7,7,$preto);
		imagefilledellipse($im,$w/2,$h/2-$c*$uy,7,7,$preto);     
		imageline($im,$w/2,0,$w/2,$h,$preto);  //definiчуo dos
		imageline($im,0,$h/2,$w,$h/2,$preto);  //eixos x e y 
		$k=(-$w/$ux)/2;  //define a quantidade de linhas horizontais, e щ definido como contador para escrever o numero associado
		for($i=0;$i<$w;$i+=$ux){
			imageline($im,$i,0,$i,$h,$cinza);
			if($k==$x1||$k==$x2||$k==$xv){
				imagettftext($im,7,0,$i,$h/2+10,$vermelho,$fonte,"$k"); //destaca de vermelho x1,x2 e xv
			}
			else{
				imagettftext($im,7,0,$i,$h/2+10,$preto,$fonte,"$k");
			}
			$k++;
		}
		imageline($im,$w/2+$xv*$ux,$h/2,$w/2+$xv*$ux,$h/2-$yv*$uy,$vermelho);
		$k=($h/$uy)/2;	//define a quantidade de linhas verticais, e щ definido como contador para escrever o numero associado
		for($i=0;$i<$h;$i+=$uy){
			if($k!=0){
				imageline($im,0,$i,$w,$i,$cinza);
				if($k==$yv||$k==$c){
					imagettftext($im,7,0,$w/2+2,$i,$vermelho,$fonte,"$k"); //destaca de vermelho yv e c
				}
				else{
					imagettftext($im,7,0,$w/2+2,$i,$preto,$fonte,"$k");
				}
			}
			$k--;
		}
		imageline($im,$w/2+$xv*$ux,$h/2-$yv*$uy,$w/2,$h/2-$yv*$uy,$vermelho);
		if($a<0||$delta==0){
			$d=-10;
		}							//por pura estщtica, serve para escrever as coordenadas 
		else{						//no local onde nуo se sobreponha ao grсfico
			$d=10;
		}
		imagettftext($im,7,0,$w/2+$xv*$ux,$h/2-$yv*$uy+$d,$vermelho,$fonte,"($xv,$yv)");
		imagettftext($im,7,0,$w/2+$x1*$ux,$h/2+2*$d,$vermelho,$fonte,"($x1,0)");
		imagettftext($im,7,0,$w/2+$x2*$ux+$d,$h/2+2*$d,$vermelho,$fonte,"($x2,0)");
		$x0=$k;
		$xf=-$k;
		$p2x=$x0;
		$p2y=f($p2x);
		while($p2x<=$xf){
			$p1x=$p2x;
			$p1y=$p2y;
			$p2x=$p1x+$variacao;
			$p2y=f($p2x);
			imageline($im,$w/2+$ux*$p1x,$h/2-$uy*$p1y,$w/2+$ux*$p2x,$h/2-$uy*$p2y,$preto);
		}
		imagefilledrectangle($im,5*$w/6,5*$h/6,$w,$h,$preto); //retangulo que expѕe os resultados
		imagettftext($im,15,0,5*$w/6,5*$h/6+20,$fundo,$fonte,"\nAs raizes sуo respectivamente:\nx1 = $x1 e x2 = $x2\nO x do vщrtice e o y do vщrtice sуo,\nrespectivamente:\nxv = $xv e yv = $yv\nA parсbola intercepta \no eixo y no ponto c=$c");
		header("content-type:image/png");
		imagepng($im);
		imagecolordeallocate($im,$preto);
		imagecolordeallocate($im,$fundo);
		imagecolordeallocate($im,$cinza);
		imagecolordeallocate($im,$vermelho);
		imagedestroy($im);
	}
	//colocar pontos nos locais do eixo cortado pela parabola, que indicam as raizes
?>