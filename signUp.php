<?php
include("connect1.php");
$x=$_POST['firstname'];
$x1=$_POST['lastname'];
$x2=$_POST['uname'];
$x3=$_POST['dob'];
$x4=$_POST['sex'];
$x5=$_POST['email'];
$x6=$_POST['password'];
$x7=$_POST['country'];
$x8=$_POST['hint'];
$x9=$_POST['answer'];
$sql = "INSERT INTO signup(fname,lname,uname,dob,gender,email,password,country,hques,hans) values($x,$x1,$x2,$x3,$x4,$x5,$x6,$x7,$x8,$x9)";
if(!(mysqli_query($link, $sql)))
	{
						echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
					}
						mysqli_close($link);
?>
