Comandos a serem utlizados:
<?php 
$im=imagecreatetruecolor($w,$h); //w e h s�o a largura e altura da imagem respectivamente
imageline($im,$x1,$y1,$x2,$y2,$cor);//cria uma linha na imagem
imagedestroy($im);//libera a mem�ria asociada � imagem
imagerectangle($im,$x1,$y1,$x2,$y2,$cor);//cria um ret�ngulo (s� a borda)
imagefilledrectangle($im,$x1,$y1,$x2,$y2,$cor);//cria um ret�ngulo (preenchido)
$cor=imagecolorallocate($im,$r,$g,$b);//gera uma cor pelo padr�o RGB, que ser� alocada
imagecolordeallocate($im,$cor);//define imagem e cor
imagepng($sim);//gerar o formato
?>