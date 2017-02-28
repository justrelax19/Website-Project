<?php
$_SESSION["status"]="NO";
session_destroy();
header("Location:../Login/login1.php");
?>