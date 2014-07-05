<?php
require 'Page.inc';
require 'sql_utils.inc';
require 'common_utils.inc';
require 'Constants.php';

class ValidatorPage extends Page
{
  const DOWNLOAD_PAGE = "http://www.metropolitanparc.com/download.php";
  public $passCode = "";
	
  function __construct($title, $passCode)
  {
	parent::__construct($title);
	$this->passCode = @trim($passCode); // Trim the passcode
  }

  public function Display()
  {
  	// Redirect if coming straight to this page
  	if($this->passCode == '')
  	{
  		header("location: HomePage.php");
  	}
  	
  	echo "<html>\n<head>\n";  	
  	
  	$this->displayJS();
  	$this->displayStyle();
  	$this->displayTitle();
  	
  	echo "</head>\n<body>";
  	echo "<p id=\"response\">";
  	
  	$authenticattionResult = SqlUtils::authenticate($this->passCode);
  	if($authenticattionResult->resultCode == AuthenticationResult::INVALID_PASSCODE)
  	{
  		$this->displayBodyOnError();
  	}
  	elseif($authenticattionResult->resultCode == AuthenticationResult::DOWNLOAD_LIMIT_REACHED)
  	{
  		$this->displayBodyOnDownloadLimitReached($authenticattionResult->name);
  	}
  	else
  	{
  		$this->setSession($authenticattionResult->name,$this->passCode);
  		$this->displayBodyOnSuccess($authenticattionResult->name);
  	}
  	echo "</p>";
  	echo "</body>\n</html>\n";
  }
  
  protected function displayJS()
  {
  }
  
  private function displayBodyOnSuccess($name)
  {
  	echo $name."<br> Thank you for downloading Metropolitan Parc's Album One";
  	header('Refresh: 2; url='.ValidatorPage::DOWNLOAD_PAGE);
  }
  
  private function displayBodyOnError()
  {
  	echo "Passphrase not recognised. Please try again";
  }
  
  private function displayBodyOnDownloadLimitReached($name)
  {
  	echo $name."<br>You have reached your maximum number of downloads. To request a new ".
  	"passcode, please contact us: metropolitanparc@gmail.com";
  }
  
  private function setSession($name, $passCode)
  {
  	session_start();
  	$_SESSION[Constants::SESSION_USERNAME] = $name;
  	$_SESSION[Constants::SESSION_PASSCODE] = $passCode;
  }
  
  protected function displayFooter()
  {
  	
  }
}