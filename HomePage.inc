<?php
require 'Page.inc';

class HomePage extends Page
{
  function __construct()
  {
	parent::__construct("Metropolitan Parc Official Website");
  }

  public function Display()
  {
  	echo "<html>\n<head>\n";
  	
  	$this->displayJS();
  	$this->displayStyle();
  	$this->displayTitle();
  	$this->displayBody();
  	
  	echo "</head>\n</html>\n";
  }
  
  protected function displayJS()
  {
  	?>
    <script type="text/javascript">
    function checkContent( form )
    {
      var passcode =  form.passcode.value;
      if(passcode == '')
      {
        var element = document.getElementById('jsresponse');
        element.innerHTML = "Invalid passphrase!";
        return false;
      }
      return true;
    }
  
    function clearResponse()
    {
        document.getElementById('response').innerHTML = '';
    }
    </script>
  <?php
  }
  
  protected function displayBody()
  {
  	?>
  	<body>
  			<div id="passcodeForm">
	    		<form name="form" id="inputform" method="post" onSubmit="return checkContent(this);" action="ValidatorPage.php">
    	   			 <input type="text" name="passcode" id="passcode" onFocus="clearResponse();" oninput="clearResponse()" placeholder="Passphrase"/>
    				<b id="jsresponse"/>
    			</form>
			</div>
	</body> 	
  	<?php
  }
  
  protected function displayFooter()
  {
  	
  }
}