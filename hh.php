// Attempt insert query execution
(include "connect1.php");
$sql = "select * from dept";
if(mysqli_query($link, $sql)){
  while($sql = mysql_fetch_assoc($extract))
	 {
	$home[]=$sql['name'];
	}
	 foreach($home as $name){
     echo $name;
	 
	 }

  
  
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
 