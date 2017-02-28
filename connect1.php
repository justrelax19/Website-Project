<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = new mysqli("localhost", "root", "", "project");
 
// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
 
/* $sql = "select * from dept";
$extract=$link->query($sql);
if(mysqli_query($link, $sql)){
  while($sql=$extract->fetch_assoc())
	 {
		 echo "name: ".
		 $sql["dname"]. "<br>" ;
		 
		 echo "id: ".
		 $sql["dno"]. "<br>" ;
	 }
}
else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}

// Close connection
mysqli_close($link);*/
?>