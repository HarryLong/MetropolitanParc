<?php
require 'sql_utils.inc';
require 'Constants.php';

	session_start();

	if(isset($_SESSION[Constants::SESSION_USERNAME]) && isset($_SESSION[Constants::SESSION_PASSCODE])) {
		$name = $_SESSION[Constants::SESSION_USERNAME];
		$passcode = $_SESSION[Constants::SESSION_PASSCODE];
		if(SqlUtils::authenticate($passcode, false)->resultCode != AuthenticationResult::VALID_PASSCODE) 
		{ 
			Destroy(); 
		}
	}
	else
	{
		Destroy();
	}
	
	function Destroy() {
		session_destroy();
		header("location: HomePage.php");
	}
?>
