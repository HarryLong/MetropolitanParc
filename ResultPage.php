<?php
require("ResultPage.inc");
date_default_timezone_set('UTC'); 

$decisionTime = mktime(0, 0, 0, 12, 18);
$now = mktime();

$resultPage = new ResultPage();

if($now >= $decisionTime)
{
	$resultPage->setGenerateChar(TRUE);
}
else
{
	$resultPage->setGenerateChar(FALSE);
}

$resultPage->Display();
?>