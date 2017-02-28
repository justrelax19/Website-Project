<?php
     include "connect.php";
     $extract=mysql_query("SELECT * FROM a");
     $row = mysql_fetch_assoc($extract) or die(mysql_error());
     $home=       $row['tid_1'];
     echo $home
?>