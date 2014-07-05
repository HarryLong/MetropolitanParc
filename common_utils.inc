<?php
class CommonUtils
{
	public static function sendFile($path)
	{
// 		ob_end_clean();
		if (!is_file($path) or connection_status() != CONNECTION_NORMAL) 
		{
			return false;
		}
		
		HEADER("Cache-Control: no-store, no-cache, must-revalidate");
		HEADER("Cache-Control: post-check=0, pre-check=0", FALSE);
		HEADER("Pragma: no-cache");
		HEADER("Content-Type: application/octet-stream");
		HEADER("Content-Length: ".(string)(FILESIZE($path)));
		HEADER("Content-Disposition: inline; filename=$path");
		HEADER("Content-Transfer-Encoding: binary\n");
		
		if($file = FOPEN($path, 'rb')) {
			WHILE(!FEOF($file) and (CONNECTION_STATUS()==0)) {
				PRINT(FREAD($file, 1024*8));
				FLUSH();
			}
			FCLOSE($file);
		}
		RETURN((connection_status() == CONNECTION_NORMAL) and !connection_aborted());
	}
}