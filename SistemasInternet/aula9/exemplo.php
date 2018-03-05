<?php
	class x{
		public function __construct(){
			echo " 1 ";
		}
	}
	class y extends x{
		function __construct(){
			parent::__construct(); //sem o parent:: ele so imprime 2...
			echo " 2 ";
		}
	}
	$a=new y();
?>