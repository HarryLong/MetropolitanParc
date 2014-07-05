<?php
abstract class Page
{
  // class Page's attributes
  public $title;
  
  function __construct($title = "Metropolitan Parc Official Website")
  {
	$this->$title = $title;
  }  

  protected function displayTitle()
  {
  	echo "<title>".$this->title."</title>";
  }
  
  protected abstract function displayFooter();
  
  protected abstract function displayJS();
  
  protected function displayStyle()
  {
?>
  	<style type="text/css">

	@font-face {
	font-family: Alternate_Gothic_No2;
    src: url('fonts/Alternate Gothic No2 BT.ttf'), 
    	 url('fonts/Alternate Gothic No2 BT.ttf'); /* IE */
	}

  	#passcodeForm{
  	position: fixed;
  	top: 50%;
  	left: 50%;
  	margin-top: -10px;
  	margin-left: -100px;
  	}
  	
  	#passcode{
 	  display:inline;
	  border:1px solid #000000;
  	opacity: 0.8;
  	text-align:center;
  	width:200px;
  	height:20px;
  	}
  	
  	#jsresponse{
  	color:red;
  	font-size:15;
  	}

  	#response{
  	font-family:Alternate_Gothic_No2;
  	font-size:30;
  	}
  	
  	body
	{
    background-color: #F2F4E6;
    background-image: url('background_LQ.jpg');
    background-position: center center; /* First value is from left and second is from top. You can use use number as well*/
    background-repeat: no-repeat;
    background-attachment: fixed;
    margin-right: auto;
    margin-left: auto;
    -moz-background-size: contain;
    background-size: contain;
/*  	background-size: 100% 100%; */
 	text-align: center; 
	}​
}
  	
  	</style>
<?php
  }
}
  