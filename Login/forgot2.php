<!doctype html>
<html>
	<head>
		<meta charset='utf-8'>
		<title>Change Password </title>
		<link rel="stylesheet" href="../pages/main.css">
	</head>
	
	<body>
	<?php
// define variables and set to empty values
session_start();
$newpw =$confpw="";
$submitnewpw="";


if ($_SERVER["REQUEST_METHOD"] == "POST")
{
   
      
      $submitnewpw = $_POST['newpw'];
	  include("connect1.php");
	  if(!preg_match('/^(?=.*\d)(?=.*[@#\-_$%^&+=ยง!\?])(?=.*[a-z])(?=.*[A-Z])[0-9A-Za-z@#\-_$%^&+=ยง!\?]{8,20}$/', $_POST["newpw"]))
	  {
		  //header('Location:http://localhost//programs/error.php');
		  echo "Password doesn't meet the requirements! Please try again!";
	  }
      else
	  {
		  $submitpasswordencr2=md5($submitnewpw) or (mysqli_error($link));  
		  if($submitpasswordencr2)
			{
				$data=$_SESSION["forgotpwdemail"];
			  $write1="UPDATE signup set password = '$submitpasswordencr2' where email = '$data';";
			 // $extract1=$link->query($write);
			 // $nn=mysqli_query($link,$write);
			  if(!(mysqli_query($link,$write1)))
			  {
				  echo "ERROR: Could not able to execute $sql. ";
			  }
			  else
			  {
				 // header('Location:http://localhost//programs/successful.php');
				  echo "Your password changed Successfully!";
				  header("Location:login1.php");
			  }
			}
		  
	  }
	  }
	  

	
	 
	 

function test_input($data)
{
     $data = trim($data);
     $data = stripslashes($data);
     $data = htmlspecialchars($data);
     return $data;
}

?>

	<form method="post" action="<?php echo $_SERVER['PHP_SELF'];?>">
	<fieldset>
		<legend><strong>Change Password</strong></legend>
		Enter your new password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="password" id="newpw" name="newpw" onclick="pwDisp()" onfocus="pwDisp()" required>
	  <script>
		function pwDisp()
		{
			alert(" at least one lowercase character\n at least one uppercase character\n at least one digit\n at least one special sign of @#-_$%^&+=ยง!?\n Between 8 to 20 characters");
			
		}
	  </script>
	  <br><br>
			  
	   Confirm Password:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	  <input type="password" name="confpw" required>
	</fieldset>
	
	<input type="submit" value="Next">
	  <input type="reset" value="Reset">
	  </form>
	</body>
</html>
