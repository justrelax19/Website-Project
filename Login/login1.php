<?php
session_start();
?>
<html>
<head>
<link rel="stylesheet" href="login.css">
</head>
<body>
	<div id="allcontent">
	<form action= "<?php echo $_SERVER['PHP_SELF'];?>" method="post">
		<h1> Login to your account:</h1>
		<input type="text" name="uname" placeholder="Enter your username"><br><br>
		<input type="password" name="password" placeholder="Enter your Password"><br><br>
		<input type="submit" value="Log In"><br>
		<?php
if(isset($_POST['uname']))
{
	include 'connect1.php';
	$uname=$_POST['uname'];
	$password=$_POST["password"];
	$password=md5($password);
	$q="select * from signup where uname='$uname' and password='$password'";
	$res=$link->query($q);
	if($res->num_rows>0)
	{
		
		$_SESSION["uname"]="$uname";
		$_SESSION["status"]="YES";
		header("Location:../Pages/welcome.php");
	}
	else
	{
	echo "<h3 style='color:white'>Wrong Username Or Password</h3>";	
	}
}
?>
		<a href="../SignUp/proform.php">Sign Up</a>&nbsp;&nbsp;
		<a href="../Login/forgot.php">Forgot Password</a>
	</form>
	</div>
</body>
</html>