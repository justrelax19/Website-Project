<?php
include("connect1.php");
$sql = "select * from dept";
$extract=$link->query($sql);
if(mysqli_query($link, $sql)){
  while($sql=$extract->fetch_assoc())
	 {
		 echo "name: ".
		 $sql["dname"]. "<br>" ;
		 
		 echo "id: ".
		 $sql["dno"]. "<br>" ;
		 //echo $sql;
	 }
}
else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
mysqli_close($link);
?>