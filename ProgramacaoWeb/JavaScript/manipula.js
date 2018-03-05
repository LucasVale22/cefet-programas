function valida_gerente() { 
var login=document.form1.login.value;
var senha=document.form1.senha.value;
if(login=="admin" && senha=="gerente")
	return true;
else{
	alert("Usuário ou senha incorretos!");
	document.form1.senha.value="";
	} 
	return false; 
}
function analise_func(a,c,qv,qh,qr){
	var n1,n2;
	a=parseInt(a);
	c=parseInt(c);
	qh=parseInt(qh);
	qv=parseInt(qv);
	qr=parseInt(qr);
	n1 = ((a * 10) + c + qh + (qv * 10)) / 26;
	n2=qr*5;
	if(n2>60)
		alert("Funcionário com reclamações acima da média. Nota1: "+n1+" e Nota2: "+n2);
	else{
		if(n1>8 && n2<20)
			alert("Funcionário excelente. Nota1: "+n1+" e Nota2: "+n2);
		else
			alert("Funcionário dentro da média. Nota1: "+n1+" e Nota2: "+n2);
		}
}
		