<?php
require("ValidatorPage.inc");

$passcode = $_POST['passcode'];

$validatorPage = new ValidatorPage("Enjoy the album!", $passcode);
$validatorPage->Display();

?>