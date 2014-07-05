<?php

class SqlUtils
{	
	public static function authenticate($passcode, $checkDownloadcount = true)
	{
		$authenticationResult = new AuthenticationResult();
		$passcode = @trim($passcode);
		
		if(!is_numeric($passcode)) // Don't even check if it is not a number
		{
			return $authenticationResult; // Default return code = failed
		}
		
		$query = "select ".Columns::name.",".Columns::download_count." from ".Tables::users." where ".Columns::passcode."=".$passcode.";";

		$result = SqlUtils::sql_query($query);
		
		if($result->num_rows == 1)
		{
			$row = $result->fetch_assoc();
			$downloadCount = intval($row[Columns::download_count]);
			$authenticationResult->setName($row[Columns::name]);
			if($checkDownloadcount)
			{
				if($downloadCount < Configuration::maxDownloads)
				{
					$authenticationResult->setResultCode(AuthenticationResult::VALID_PASSCODE);
					SqlUtils::setDownloadCount($passcode, ++$downloadCount);
				}
				else
				{
					$authenticationResult->setResultCode(AuthenticationResult::DOWNLOAD_LIMIT_REACHED);
				}
			}
			else
			{
				$authenticationResult->setResultCode(AuthenticationResult::VALID_PASSCODE);
			}
		
		}
		return $authenticationResult; // Default return code = failed
	}
	
	public static function getRandomChar()
	{
		$query = "SELECT * FROM ".Tables::random_character.";";
		$result = SqlUtils::sql_query($query);

		if($result->num_rows == 1)
		{
			$row = $result->fetch_assoc();
			return $row[Columns::random_char];
		}

		if(SqlUtils::setRandomChar())
		{
			return SqlUtils::getRandomChar();			
		}

		return "";
	} 

	private static function setRandomChar()
	{
		$random_char = chr(65 + rand(0 , 25));
		$query = "INSERT INTO ".Tables::random_character."(".Columns::random_char.") VALUES(\"".$random_char."\");";
		return SqlUtils::sql_query($query);
	}

	private static function setDownloadCount($passcode, $downloadcount)
	{
		$query = "UPDATE ".Tables::users.
				" SET ".Columns::download_count."=".$downloadcount.
				" WHERE ".Columns::passcode."=".$passcode.";";
		
		$result = SqlUtils::sql_query($query);
	}
	
	private static function sql_query($query)
	{
		// Connect to database
		$mysqli = new mysqli(Configuration::server, 
							 Configuration::username, 
							 Configuration::password, 
							 DataBases::metropolitan_parc);
		
		// Ensure we connected OK
		if ($mysqli->connect_errno) {
			die('Connect Error: ' . $mysqli->connect_error);
		}
				
		$result = $mysqli->query($query);
		
		if(!$result)
		{
			$message  = 'Invalid query: ' . mysql_error() . "\n";
			die($message);
		}
		
		return $result;
	}	
}

class Columns
{
	const passcode = 'passcode';
	const name = 'name';
	const download_count = 'download_count';
	const random_char = 'RANDOM_CHAR';
}

class Tables
{
	const users = 'users';
	const random_character = 'random_character';
}

class DataBases
{
	const metropolitan_parc= 'metropolfparc';
// 	const metropolitan_parc= 'metropolitan_parc';
	
}

class Configuration
{
	const server = 'mysql51-90.perso';
	const username = 'metropolfparc';
	const password = 'QliEFlFU';
// 	const server = '127.0.0.1';
//  	const username = 'root';
//  	const password = 'f458ital';
	const maxDownloads = 2; // i.e 3 with 0
}

class AuthenticationResult
{
	const INVALID_PASSCODE = 0;
	const DOWNLOAD_LIMIT_REACHED = 1;
	const VALID_PASSCODE = 2;
	
	public $name = '';
	public $resultCode = 0;
	
	function setResultCode($resultCode)
	{
		$this->resultCode = $resultCode;
	}
	
	function setName($name)
	{
		$this->name = $name;
	}
}