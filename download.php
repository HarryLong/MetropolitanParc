<?php
include("authentication.php");

$path = 'files/Album_one.zip';
$filename = 'Album_one.zip';

HEADER("Cache-Control: no-store, no-cache, must-revalidate");
HEADER("Cache-Control: post-check=0, pre-check=0", FALSE);
HEADER("Pragma: no-cache");
HEADER("Content-Type: application/octet-stream");
HEADER("Content-Length: ".(string)(FILESIZE($path)));
HEADER("Content-Disposition: inline; filename=$filename");
HEADER("Content-Transfer-Encoding: binary\n");

if($file = FOPEN($path, 'rb')) {
	WHILE(!FEOF($file) and (CONNECTION_STATUS()==0)) {
		PRINT(FREAD($file, 1024*8));
		FLUSH();
	}
	FCLOSE($file);
}

start_session;
session_destroy();

?>