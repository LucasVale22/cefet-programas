function analisar(so,ia,bd){
	var part=document.form1.part.value;
	var end=document.form1.end.value;
	var cep=document.form1.cep.value;
	var mail=document.form1.mail.value;
	var cid=document.form1.cid.value;
	if(part==""||end==""||cep==""||mail==""||cid==""){
		alert("Preencha os campos em branco!");
		return false;
	}
	else
		return true;
}