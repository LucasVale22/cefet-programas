<?php
	$im=imagecreatetruecolor(800,600);
	$preto=imagecolorallocate($im,0,0,0);
	$amarelo=imagecolorallocate($im,100,50,0);
	imagefilledrectangle($im,20,20,780,580,$amarelo);
	imagerectangle($im,20,20,780,580,$preto);
	header("content-type:image/png");//informa ao browser o formato que se está enviando...
	imagepng($im);
	imagecolordeallocate($im,$preto);
	imagecolordeallocate($im,$amarelo);
	imagedestroy($im);
?>