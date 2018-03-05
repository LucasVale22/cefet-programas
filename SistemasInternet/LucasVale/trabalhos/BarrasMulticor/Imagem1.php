Comandos a serem utlizados:
<?php 
$im=imagecreatetruecolor($w,$h); //w e h são a largura e altura da imagem respectivamente
imageline($im,$x1,$y1,$x2,$y2,$cor);//cria uma linha na imagem
imagedestroy($im);//libera a memória asociada à imagem
imagerectangle($im,$x1,$y1,$x2,$y2,$cor);//cria um retângulo (só a borda)
imagefilledrectangle($im,$x1,$y1,$x2,$y2,$cor);//cria um retângulo (preenchido)
$cor=imagecolorallocate($im,$r,$g,$b);//gera uma cor pelo padrão RGB, que será alocada
imagecolordeallocate($im,$cor);//define imagem e cor
imagepng($sim);//gerar o formato
?>